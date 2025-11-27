#include "raylib.h"
#include "selecaoagentes.h"

int OpcaoStart = 0;
int OpcaoOptions = 1;
int OpcaoExit = 2;

int TelaMenu = 0;
int TelaOptions = 1;
int TelaExit = 2;

int OptionsAtual = 2;
int dificuldade = 5;

int voltar_menu = 0;

int main(void) {
    InitWindow(1920, 1080, "Hellbound: Black Jack");
    if (IsWindowFullscreen() == 0) {
        ToggleFullscreen();
    }
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    Texture2D TexturaStart = LoadTexture("assets/tela_de_titulo_start.png");
    Texture2D TexturaOptions = LoadTexture("assets/tela_de_titulo_opcoes.png");
    Texture2D TexturaExit = LoadTexture("assets/tela_de_titulo_sair.png");

    Texture2D TexturaOptions1 = LoadTexture("assets/tela_opcoes1.jpg");
    Texture2D TexturaOptions2 = LoadTexture("assets/tela_opcoes2.jpg");
    Texture2D TexturaOptions3 = LoadTexture("assets/tela_opcoes3.jpg");

    int MenuOpcaoAtual = OpcaoStart;
    int Tela = TelaMenu;

    while (WindowShouldClose() == 0 && Tela != TelaExit) {
        if (Tela == TelaMenu) {
            HideCursor();
            if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                MenuOpcaoAtual++;
                if (MenuOpcaoAtual > 2) {
                    MenuOpcaoAtual = 0;
                }
            }
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
                MenuOpcaoAtual--;
                if (MenuOpcaoAtual < 0) {
                    MenuOpcaoAtual = 2;
                }
            }

            if (IsKeyPressed(KEY_ENTER)) {
                if (MenuOpcaoAtual == OpcaoStart) {
                    UnloadTexture(TexturaStart);
                    UnloadTexture(TexturaOptions);
                    UnloadTexture(TexturaExit);

                    UnloadTexture(TexturaOptions1);
                    UnloadTexture(TexturaOptions2);
                    UnloadTexture(TexturaOptions3);

                    RodarTelaSelecao();
                    
                    if (voltar_menu == 1) {
                        Tela = TelaMenu;
                        voltar_menu = 0;

                        TexturaStart = LoadTexture("assets/tela_de_titulo_start.png");
                        TexturaOptions = LoadTexture("assets/tela_de_titulo_opcoes.png");
                        TexturaExit = LoadTexture("assets/tela_de_titulo_sair.png");
                        
                        TexturaOptions1 = LoadTexture("assets/tela_opcoes1.jpg");
                        TexturaOptions2 = LoadTexture("assets/tela_opcoes2.jpg");
                        TexturaOptions3 = LoadTexture("assets/tela_opcoes3.jpg");
                        MenuOpcaoAtual = OpcaoStart;
                    } else {
                        Tela = TelaExit;
                    }
                } else if (MenuOpcaoAtual == OpcaoOptions) {
                    Tela = TelaOptions;
                } else if (MenuOpcaoAtual == OpcaoExit) {
                    Tela = TelaExit;
                }
            }
        } else if (Tela == TelaOptions) {
            if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                OptionsAtual++;
                if (OptionsAtual > 3) {
                    OptionsAtual = 1;
                }
            }
            if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                OptionsAtual--;
                if (OptionsAtual < 1) {
                    OptionsAtual = 3;
                }
            }

            if (OptionsAtual == 1) {
                dificuldade = 3;
            } else if (OptionsAtual == 2) {
                dificuldade = 5;
            } else {
                dificuldade = 7;
            }
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER)) {
                Tela = TelaMenu;
            }
        }

        if (Tela != TelaExit) {
            BeginDrawing();
            ClearBackground(BLACK);
            if (Tela == TelaMenu) {
                Texture2D TexturaDesenhar = TexturaStart;

                if (MenuOpcaoAtual == OpcaoStart) {
                    TexturaDesenhar = TexturaStart;
                } else if (MenuOpcaoAtual == OpcaoOptions) {
                    TexturaDesenhar = TexturaOptions;
                } else if (MenuOpcaoAtual == OpcaoExit) {
                    TexturaDesenhar = TexturaExit;
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
                destino.width = GetScreenWidth();
                destino.height = GetScreenHeight();
                origem.x = 0.0f;
                origem.y = 0.0f;

                DrawTexturePro(TexturaDesenhar, original, destino, origem, 0.0f, WHITE);
            } else if (Tela == TelaOptions) {
                Texture2D TexturaDesenhar;

                if (OptionsAtual == 1) {
                    TexturaDesenhar = TexturaOptions1;
                } else if (OptionsAtual == 2) {
                    TexturaDesenhar = TexturaOptions2;
                } else {
                    TexturaDesenhar = TexturaOptions3;
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
                destino.width = GetScreenWidth();
                destino.height = GetScreenHeight();
                origem.x = 0.0f;
                origem.y = 0.0f;

                DrawTexturePro(TexturaDesenhar, original, destino, origem, 0.0f, WHITE);
            }
            EndDrawing();
        }
    }
    UnloadTexture(TexturaStart);
    UnloadTexture(TexturaOptions);
    UnloadTexture(TexturaExit);

    UnloadTexture(TexturaOptions1);
    UnloadTexture(TexturaOptions2);
    UnloadTexture(TexturaOptions3);
    return 0;
}
