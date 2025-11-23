#include "raylib.h"
#include "hub.h"
#include "cursor.h"
#include <stdio.h>
#include <string.h>
#include "variaveis.h"
#include "grafico.h"
#include "loads.h"
#include "batalha.h"
#include "loja.h"
#include "poco.h"

void TelaHub(Personagem personagem) {
    SetWindowTitle("Hellbound Blackjack - HUB");
    SetTargetFPS(60);

    load_coracoes();
    Texture2D background = LoadTexture("assets/BACKGROUND.png");
    Texture2D PocoHover = LoadTexture("assets/poco_background.png");
    Texture2D LojaHover = LoadTexture("assets/loja_background.png");
    Texture2D BatalhaHover = LoadTexture("assets/batalha_background.png");

    Texture2D IconGuerreiro = LoadTexture("assets/guerreiro_icon.png");
    Texture2D IconArqueiro = LoadTexture("assets/arqueiro_icon.png");
    Texture2D IconMaga = LoadTexture("assets/maga_icon.png");

    loadCursor();
    HideCursor();
    
    bool foiParaBatalha = false;
    
    while (WindowShouldClose() == 0) {
        float TelaLargura = GetScreenWidth();
        float TelaAltura = GetScreenHeight();
        float ratioX = TelaLargura / 1920.0f;
        float ratioY = TelaAltura / 1080.0f;
        Rectangle hitboxPoco;
        Rectangle hitboxLoja;
        Rectangle hitboxTorreBatalha;
        Rectangle hitboxBaseBatalha;

        hitboxPoco.x = 390 * ratioX;
        hitboxPoco.y = 687 * ratioY;
        hitboxPoco.width = 130 * ratioX;
        hitboxPoco.height = 90 * ratioY;

        hitboxLoja.x = 1380 * ratioX;
        hitboxLoja.y = 700 * ratioY;
        hitboxLoja.width = 160 * ratioX;
        hitboxLoja.height = 100 * ratioY;

        hitboxTorreBatalha.x = 810 * ratioX;
        hitboxTorreBatalha.y = 190 * ratioY;
        hitboxTorreBatalha.width = 200 * ratioX;
        hitboxTorreBatalha.height = 340 * ratioY;

        hitboxBaseBatalha.x = 680 * ratioX;
        hitboxBaseBatalha.y = 530 * ratioY;
        hitboxBaseBatalha.width = 540 * ratioX;
        hitboxBaseBatalha.height = 260 * ratioY;
        
        Vector2 mousePos = GetMousePosition();

        clickCursor(IsMouseButtonDown(MOUSE_LEFT_BUTTON));
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePos, hitboxPoco)) {
                TelaPoco(&personagem);
            } else if (CheckCollisionPointRec(mousePos, hitboxLoja)) {
                TelaLoja(&personagem);
            }  else if (CheckCollisionPointRec(mousePos, hitboxTorreBatalha) || CheckCollisionPointRec(mousePos, hitboxBaseBatalha)) {
                UnloadTexture(background);
                UnloadTexture(PocoHover);
                UnloadTexture(LojaHover);
                UnloadTexture(BatalhaHover);

                UnloadTexture(IconGuerreiro);
                UnloadTexture(IconArqueiro);
                UnloadTexture(IconMaga);
                
                foiParaBatalha = true;
                TelaBatalha(personagem);
                break;
            }
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        Rectangle destino;
        Rectangle original;
        Vector2 origem;

        destino.x = 0.0f;
        destino.y = 0.0f;
        destino.width = TelaLargura;
        destino.height = TelaAltura;
        original.x = 0.0f;
        original.y = 0.0f;
        original.width = background.width;
        original.height = background.height;
        origem.x = 0.0f;
        origem.y = 0.0f;

        DrawTexturePro(background, original, destino, origem, 0.0f, WHITE);

        if (CheckCollisionPointRec(mousePos, hitboxPoco) == 1) {
            original.x = 0.0f;
            original.y = 0.0f;
            original.width = PocoHover.width;
            original.height = PocoHover.height;

            DrawTexturePro(PocoHover, original, destino, origem, 0.0f, WHITE);
        } else if (CheckCollisionPointRec(mousePos, hitboxLoja) == 1) {
            original.x = 0.0f;
            original.y = 0.0f;
            original.width = LojaHover.width;
            original.height = LojaHover.height;

            DrawTexturePro(LojaHover, original, destino, origem, 0.0f, WHITE);
        } else if (CheckCollisionPointRec(mousePos, hitboxTorreBatalha) == 1 || CheckCollisionPointRec(mousePos, hitboxBaseBatalha) == 1) {
            original.x = 0.0f;
            original.y = 0.0f;
            original.width = BatalhaHover.width;
            original.height = BatalhaHover.height;

            DrawTexturePro(BatalhaHover, original, destino, origem, 0.0f, WHITE);
        }

        if (strcmp(personagem.nome, "Guerreiro") == 0) {
            original.width = IconGuerreiro.width;
            original.height = IconGuerreiro.height;
            destino.x = ratioX;
            destino.y = ratioY;
            destino.width = IconGuerreiro.width;
            destino.height = IconGuerreiro.height;

            DrawTexturePro(IconGuerreiro, original, destino, origem, 0.0f, WHITE);
        } else if (strcmp(personagem.nome, "Arqueiro") == 0) {
            original.width = IconArqueiro.width;
            original.height = IconArqueiro.height;
            destino.x = ratioX;
            destino.y = ratioY;
            destino.width = IconArqueiro.width;
            destino.height = IconArqueiro.height;

            DrawTexturePro(IconArqueiro, original, destino, origem, 0.0f, WHITE);
        } else if (strcmp(personagem.nome, "Maga") == 0) {
            original.width = IconMaga.width;
            original.height = IconMaga.height;
            destino.x = ratioX;
            destino.y = ratioY;
            destino.width = IconMaga.width;
            destino.height = IconMaga.height;

            DrawTexturePro(IconMaga, original, destino, origem, 0.0f, WHITE);
        }
        desenhar_vida_player_hub();

        Font fonte;
        Vector2 posicao;
        Vector2 origem_din;

        fonte = GetFontDefault();
        posicao.x = 337.0f;
        posicao.y = 95.0f;
        origem_din.x = 0.0f;
        origem_din.y = 0.0f;
        float tamanho = 47.0f;
        float espaco = 1.0f;
        float ang = 0.0f;
        char *texto = TextFormat("%d", dinheiro_total);
        DrawTextPro(fonte, texto, posicao, origem_din, ang, tamanho, espaco, BLACK);
        
        desenharCursor();
        EndDrawing();
    }

    if (foiParaBatalha == 0) {
        load_coracoes();
        UnloadTexture(background);
        UnloadTexture(PocoHover);
        UnloadTexture(LojaHover);
        UnloadTexture(BatalhaHover);

        UnloadTexture(IconGuerreiro);
        UnloadTexture(IconArqueiro);
        UnloadTexture(IconMaga);

        ShowCursor();
        unloadCursor();
    }
}
