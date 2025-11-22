#include "raylib.h"
#include "poco.h"
#include "hub.h"
#include "cursor.h"
#include <stdio.h>
#include <string.h>

extern int dinheiro_total;

int matriz5050[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int matriz3565[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int matriz2080[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int matriz1090[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

int tentar = 0;
int sair = 1;

int contadorTentativas = 0;

void TentarSorte(Personagem *p, char *msg) {
    int linha_sorteada;
    int coluna_sorteada;
    int resultado;
    linha_sorteada = GetRandomValue(0, 9);
    coluna_sorteada = GetRandomValue(0, 9);

    if (contadorTentativas == 0) {
        resultado = matriz5050[linha_sorteada][coluna_sorteada];
    } else if (contadorTentativas == 1) {
        resultado = matriz3565[linha_sorteada][coluna_sorteada];
    } else if (contadorTentativas == 2) {
        resultado = matriz2080[linha_sorteada][coluna_sorteada];
    } else {
        resultado = matriz1090[linha_sorteada][coluna_sorteada];
    }
    contadorTentativas++;

    if (resultado == 1) {
        dinheiro_total = dinheiro_total * 2;
        strcpy(msg, "Sorte! O poco dobrou seu dinheiro!");
    } else {
        dinheiro_total = 0;
        strcpy(msg, "Azar... O poco levou todo seu dinheiro.");
    }
    p->dinheiro = dinheiro_total;
}

void TelaPoco(Personagem *personagem) {
    SetWindowTitle("Hellbound Blackjack - Poço");
    SetTargetFPS(60);
    HideCursor();
    loadCursor();

    Texture2D TextureTentar;
    Texture2D TextureSair;

    TextureTentar = LoadTexture("assets/Poco_tentarasorte.png");
    TextureSair = LoadTexture("assets/Poco_sair.png");

    int opcao;
    int SairPoco;
    char pocoMsg[256];
    opcao = tentar;
    SairPoco = 0;
    pocoMsg[0] = '\0';

    Rectangle hitboxTentar;
    Rectangle hitboxSair;
    float TelaLargura;
    float TelaAltura;
    float ratioX;
    float ratioY;

    TelaLargura = GetScreenWidth();
    TelaAltura = GetScreenHeight();
    ratioX = TelaLargura / 1920.0f;
    ratioY = TelaAltura / 1080.0f;

    hitboxTentar.x = 1.0f * ratioX;
    hitboxTentar.y = 860.0f * ratioY;
    hitboxTentar.width = 760.0f * ratioX;
    hitboxTentar.height = 100.0f * ratioY;

    hitboxSair.x = 1.0f * ratioX;
    hitboxSair.y = 960.0f * ratioY;
    hitboxSair.width = 760.0f * ratioX;
    hitboxSair.height = 100.0f * ratioY;

    while (IsMouseButtonDown(MOUSE_LEFT_BUTTON) == 1) {
        BeginDrawing();
        ClearBackground(BLACK);
        desenharCursor();
        EndDrawing();
    }

    Vector2 mousePos;
    while (SairPoco == 0 && WindowShouldClose() == 0) {
        mousePos = GetMousePosition();
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) == 1) {
            clickCursor(1);
        } else {
            clickCursor(0);
        }

        if (CheckCollisionPointRec(mousePos, hitboxTentar) == 1) {
            opcao = tentar;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
                TentarSorte(personagem, pocoMsg);
            }
        } else if (CheckCollisionPointRec(mousePos, hitboxSair) == 1) {
            opcao = sair;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
                SairPoco = 1;
                pocoMsg[0] = '\0';
            }
        }

        if (IsKeyPressed(KEY_DOWN) == 1 || IsKeyPressed(KEY_S) == 1) {
            opcao = (opcao + 1) % 2;
        }

        if (IsKeyPressed(KEY_UP) == 1 || IsKeyPressed(KEY_W) == 1) {
            opcao = (opcao + 1) % 2;
        }

        if (IsKeyPressed(KEY_ESCAPE) == 1) {
            SairPoco = 1;
            pocoMsg[0] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER) == 1) {
            if (opcao == tentar) {
                TentarSorte(personagem, pocoMsg);
            } else {
                SairPoco = 1;
                pocoMsg[0] = '\0';
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);

        Texture2D TextureDesenhar;
        if (opcao == tentar) {
            TextureDesenhar = TextureTentar;
        } else {
            TextureDesenhar = TextureSair;
        }

        Rectangle original;
        Rectangle destino;
        Vector2 origem;

        original.x = 0.0f;
        original.y = 0.0f;
        original.width = TextureDesenhar.width;
        original.height = TextureDesenhar.height;
        destino.x = 0.0f;
        destino.y = 0.0f;
        destino.width = TelaLargura;
        destino.height = TelaAltura;
        origem.x = 0.0f;
        origem.y = 0.0f;

        DrawTexturePro(TextureDesenhar, original, destino, origem, 0.0f, WHITE);

        int posX;
        int posY;
        int fontSizeMsg;
        int fontSizeDinheiro;
        posX = (int)(60.0f * ratioX);
        posY = (int)(700.0f * ratioY);
        fontSizeMsg = (int)(25.0f * ratioX);
        fontSizeDinheiro = (int)(30.0f * ratioX);

        DrawText(TextFormat("Dinheiro: %d", dinheiro_total), posX, posY, fontSizeDinheiro, RAYWHITE);

        if (pocoMsg[0] != '\0') {
            DrawText(pocoMsg, posX, posY + (int)(40.0f * ratioY), fontSizeMsg, WHITE);
        }
        desenharCursor();
        EndDrawing();
    }
    UnloadTexture(TextureTentar);
    UnloadTexture(TextureSair);
}
