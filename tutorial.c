#include "raylib.h"
#include "tutorial.h"
#include "hub.h"
#include "cursor.h"
#include <stdlib.h>

void RodarTutorial(void) {
    SetWindowTitle("Hellbound Blackjack - Tutorial");

    Texture2D TexturaDialogo1 = LoadTexture("assets/tutorial_1.png");
    Texture2D TexturaDialogo2 = LoadTexture("assets/tutorial_2.png");
    Texture2D TexturaDialogo3 = LoadTexture("assets/tutorial_3.png");
    Texture2D TexturaDialogo4 = LoadTexture("assets/tutorial_4.png");
    Texture2D TexturaDialogo5 = LoadTexture("assets/tutorial_5.png");
    Texture2D TexturaDialogo6 = LoadTexture("assets/tutorial_6.png");
    Texture2D TexturaDialogo7 = LoadTexture("assets/tutorial_7.png");
    Texture2D TexturaDialogo8 = LoadTexture("assets/tutorial_8.png");
    Texture2D TexturaDialogo9 = LoadTexture("assets/tutorial_9.png");
    Texture2D TexturaDialogo10 = LoadTexture("assets/tutorial_10.png");

    loadCursor();
    HideCursor();

    int dialogoAtual = 1;
    bool sairTutorial = false;

    while (sairTutorial == 0 && WindowShouldClose() == 0) {
        float TelaLargura = GetScreenWidth();
        float TelaAltura = GetScreenHeight();
        float ratioX = TelaLargura / 1920.0f;
        float ratioY = TelaAltura / 1080.0f;
        
        Vector2 mousePos = GetMousePosition();
        clickCursor(IsMouseButtonDown(MOUSE_LEFT_BUTTON));

        Rectangle hitboxSim;
        Rectangle hitboxNao;

        hitboxSim.x = 350 * ratioX;
        hitboxSim.y = 390 * ratioY;
        hitboxSim.width = 150 * ratioX;
        hitboxSim.height = 60 * ratioY;

        hitboxNao.x = 350 * ratioX;
        hitboxNao.y = 460 * ratioY;
        hitboxNao.width = 150 * ratioX;
        hitboxNao.height = 60 * ratioY;

        if (dialogoAtual == 1 || dialogoAtual == 2) {
            bool mouseSim = CheckCollisionPointRec(mousePos, hitboxSim);
            bool mouseNao = CheckCollisionPointRec(mousePos, hitboxNao);

            if (mouseSim) {
                dialogoAtual = 1;
            } else if (mouseNao) {
                dialogoAtual = 2;
            }

            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
                dialogoAtual = 1;
            }
            if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                dialogoAtual = 2;
            }

            bool confirmouTeclado = IsKeyPressed(KEY_ENTER);
            
            if ((mouseSim && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || (dialogoAtual == 1 && confirmouTeclado)) {
                dialogoAtual = 3;
            }
            else if ((mouseNao && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || (dialogoAtual == 2 && confirmouTeclado)) {
                sairTutorial = true;
            }
        }
        else {
            Rectangle hitboxSeta;
            bool mouseSeta;

            hitboxSeta.x = 820 * ratioX;
            hitboxSeta.y = 640 * ratioY;
            hitboxSeta.width = 93 * ratioX;
            hitboxSeta.height = 75 * ratioY;

            mouseSeta = CheckCollisionPointRec(mousePos, hitboxSeta);

            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) ||(mouseSeta && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))) {
                dialogoAtual++;
                if (dialogoAtual > 10)
                    sairTutorial = true;
            }
        }
        
        BeginDrawing();
        ClearBackground(BLACK);

        Texture2D TexturaDesenhar;
        if (dialogoAtual == 1) {
            TexturaDesenhar = TexturaDialogo1;
        } else if (dialogoAtual == 2) {
            TexturaDesenhar = TexturaDialogo2;
        } else if (dialogoAtual == 3) {
            TexturaDesenhar = TexturaDialogo3;
        } else if (dialogoAtual == 4) {
            TexturaDesenhar = TexturaDialogo4;
        } else if (dialogoAtual == 5) {
            TexturaDesenhar = TexturaDialogo5;
        } else if (dialogoAtual == 6) {
            TexturaDesenhar = TexturaDialogo6;
        } else if (dialogoAtual == 7) {
            TexturaDesenhar = TexturaDialogo7;
        } else if (dialogoAtual == 8) {
            TexturaDesenhar = TexturaDialogo8;
        } else if (dialogoAtual == 9) {
            TexturaDesenhar = TexturaDialogo9;
        } else {
            TexturaDesenhar = TexturaDialogo10;
        }

        Rectangle original;
        Rectangle destino;
        Vector2 origem;

        original.x = 0.0f;
        original.y = 0.0f;
        original.width = TexturaDesenhar.width;
        original.height = TexturaDesenhar.height;
        destino.x = 0.0f;
        destino.y = 0.0f;
        destino.width = TelaLargura;
        destino.height = TelaAltura;
        origem.x = 0.0f;
        origem.y = 0.0f;

        DrawTexturePro(TexturaDesenhar, original, destino, origem, 0.0f, WHITE);

        desenharCursor();
        EndDrawing();
    }
    UnloadTexture(TexturaDialogo1);
    UnloadTexture(TexturaDialogo2);
    UnloadTexture(TexturaDialogo3);
    UnloadTexture(TexturaDialogo4);
    UnloadTexture(TexturaDialogo5);
    UnloadTexture(TexturaDialogo6);
    UnloadTexture(TexturaDialogo7);
    UnloadTexture(TexturaDialogo8);
    UnloadTexture(TexturaDialogo9);
    UnloadTexture(TexturaDialogo10);
    unloadCursor();
}

void RodarTelaTutorial(Personagem personagem) {
    RodarTutorial();
    TelaHub(personagem);
}
