#include "raylib.h"
#include "loja.h"
#include "hub.h"
#include "cursor.h"
#include "variaveis.h"
#include "stats.h"
#include <stdio.h>

int estadoMenu = 0;
int estadoCompra = 1;
int estadoConversa = 2;

int comprar = 0;
int conversar = 1;
int sairLoja = 2;

int vida = 0;
int mais2 = 1;
int menos2 = 2;
int mais4 = 3;
int menos4 = 4;

int precos[] = { 4, 3, 3, 6, 6 };

int inventario_tem_espaco(void) {
    if (inv_count < inv_max) {
        return 1;
    }
    return 0;
}

void comprar_trinket_mais2(void) {
    int preco;

    preco = 3;

    if (dinheiro_total < preco) {
        return;
    }

    if (inventario_tem_espaco() == 0) {
        return;
    }

    dinheiro_total = dinheiro_total - preco;
    registrar_gasto(preco);

    trinket_mais2_count++;
    inv_count++;
}

void comprar_trinket_menos2(void) {
    int preco;

    preco = 3;

    if (dinheiro_total < preco) {
        return;
    }

    if (inventario_tem_espaco() == 0) {
        return;
    }

    dinheiro_total = dinheiro_total - preco;
    registrar_gasto(preco);

    trinket_menos2_count++;
    inv_count++;
}

void comprar_trinket_mais4(void) {
    int preco;

    preco = 6;

    if (dinheiro_total < preco) {
        return;
    }

    if (inventario_tem_espaco() == 0) {
        return;
    }

    dinheiro_total = dinheiro_total - preco;
    registrar_gasto(preco);

    trinket_mais4_count++;
    inv_count++;
}

void comprar_trinket_menos4(void) {
    int preco;

    preco = 6;

    if (dinheiro_total < preco) {
        return;
    }

    if (inventario_tem_espaco() == 0) {
        return;
    }

    dinheiro_total = dinheiro_total - preco;
    registrar_gasto(preco);

    trinket_menos4_count++;
    inv_count++;
}

void comprar_coracao(Personagem *p) {
    int preco;
    int vida_max;

    preco = precos[vida];

    if (dinheiro_total < preco) {
        return;
    }

    vida_max = player_vida_max;

    if (p != NULL) {
        vida_max = p->coracoes;
    }

    if (player_vida >= vida_max) {
        return;
    }

    dinheiro_total = dinheiro_total - preco;
    registrar_gasto(preco);

    player_vida++;

    if (player_vida > vida_max) {
        player_vida = vida_max;
    }
}

void comprar_itens(Personagem *p, int itemID) {
    if (itemID == vida) {
        comprar_coracao(p);
        return;
    }
    if (itemID == mais2) {
        comprar_trinket_mais2();
        return;
    }
    if (itemID == menos2) {
        comprar_trinket_menos2();
        return;
    }
    if (itemID == mais4) {
        comprar_trinket_mais4();
        return;
    }
    if (itemID == menos4) {
        comprar_trinket_menos4();
        return;
    }
}

int hitboxes_opcao_loja(int *menu_opcao) {
    Rectangle hitbox_comprar;
    Rectangle hitbox_conversar;
    Rectangle hitbox_sair;
    Vector2 mouse;
    int hover_comprar;
    int hover_conversar;
    int hover_sair;
    int confirmar;

    hitbox_comprar.x = 60.0f;
    hitbox_comprar.y = 830.0f;
    hitbox_comprar.width = 450.0f;
    hitbox_comprar.height = 60.0f;

    hitbox_conversar.x = 60.0f;
    hitbox_conversar.y = 910.0f;
    hitbox_conversar.width = 450.0f;
    hitbox_conversar.height = 60.0f;

    hitbox_sair.x = 60.0f;
    hitbox_sair.y = 990.0f;
    hitbox_sair.width = 450.0f;
    hitbox_sair.height = 60.0f;

    mouse = GetMousePosition();
    hover_comprar = 0;
    hover_conversar = 0;
    hover_sair = 0;
    confirmar = 0;

    if (CheckCollisionPointRec(mouse, hitbox_comprar) == 1) {
        hover_comprar = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_conversar) == 1) {
        hover_conversar = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_sair) == 1) {
        hover_sair = 1;
    }

    if (menu_opcao != NULL) {
        if (hover_comprar == 1) {
            *menu_opcao = comprar;
        }

        if (hover_conversar == 1) {
            *menu_opcao = conversar;
        }

        if (hover_sair == 1) {
            *menu_opcao = sairLoja;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
        if (hover_comprar == 1 || hover_conversar == 1 || hover_sair == 1) {
            confirmar = 1;
        }
    }
    return confirmar;
}

int hitboxes_itens(int *item_opcao) {
    Rectangle hitbox_vida;
    Rectangle hitbox_mais2;
    Rectangle hitbox_menos2;
    Rectangle hitbox_mais4;
    Rectangle hitbox_menos4;
    Vector2 mouse;
    int hover_vida;
    int hover_mais2;
    int hover_menos2;
    int hover_mais4;
    int hover_menos4;
    int confirmar;

    hitbox_vida.x = 90.0f;
    hitbox_vida.y = 130.0f;
    hitbox_vida.width = 700.0f;
    hitbox_vida.height = 90.0f;

    hitbox_mais2.x = 90.0f;
    hitbox_mais2.y = 240.0f;
    hitbox_mais2.width = 700.0f;
    hitbox_mais2.height = 90.0f;

    hitbox_menos2.x = 90.0f;
    hitbox_menos2.y = 350.0f;
    hitbox_menos2.width = 700.0f;
    hitbox_menos2.height = 90.0f;

    hitbox_mais4.x = 90.0f;
    hitbox_mais4.y = 460.0f;
    hitbox_mais4.width = 700.0f;
    hitbox_mais4.height = 90.0f;

    hitbox_menos4.x = 90.0f;
    hitbox_menos4.y = 570.0f;
    hitbox_menos4.width = 700.0f;
    hitbox_menos4.height = 90.0f;

    mouse = GetMousePosition();
    hover_vida = 0;
    hover_mais2 = 0;
    hover_menos2 = 0;
    hover_mais4 = 0;
    hover_menos4 = 0;
    confirmar = 0;

    if (CheckCollisionPointRec(mouse, hitbox_vida) == 1) {
        hover_vida = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_mais2) == 1) {
        hover_mais2 = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_menos2) == 1) {
        hover_menos2 = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_mais4) == 1) {
        hover_mais4 = 1;
    }

    if (CheckCollisionPointRec(mouse, hitbox_menos4) == 1) {
        hover_menos4 = 1;
    }

    if (item_opcao != NULL) {
        if (hover_vida == 1) {
            *item_opcao = vida;
        }

        if (hover_mais2 == 1) {
            *item_opcao = mais2;
        }

        if (hover_menos2 == 1) {
            *item_opcao = menos2;
        }

        if (hover_mais4 == 1) {
            *item_opcao = mais4;
        }

        if (hover_menos4 == 1) {
            *item_opcao = menos4;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
        if (hover_vida == 1 || hover_mais2 == 1 || hover_menos2 == 1 || hover_mais4 == 1 || hover_menos4 == 1) {
            confirmar = 1;
        }
    }
    return confirmar;
}

void TelaLoja(Personagem *personagem) {
    SetWindowTitle("Hellbound Blackjack - Loja");
    SetTargetFPS(60);
    HideCursor();
    loadCursor();

    Texture2D texComprar = LoadTexture("assets/Vendedor_comprar.png");
    Texture2D texConversar = LoadTexture("assets/Vendedor_conversar.png");
    Texture2D texsairLoja = LoadTexture("assets/Vendedor_sair.png");
    Texture2D texCompraItem0 = LoadTexture("assets/Vendedor_comprar_aberto_1.png");
    Texture2D texCompraItem1 = LoadTexture("assets/Vendedor_comprar_aberto_2.png");
    Texture2D texCompraItem2 = LoadTexture("assets/Vendedor_comprar_aberto_3.png");
    Texture2D texCompraItem3 = LoadTexture("assets/Vendedor_comprar_aberto_4.png");
    Texture2D texCompraItem4 = LoadTexture("assets/Vendedor_comprar_aberto_5.png");
    Texture2D texDialogo1 = LoadTexture("assets/Vendedor_conversar_aberto1.png");
    Texture2D texDialogo2 = LoadTexture("assets/Vendedor_conversar_aberto2.png");
    carregar_stats_ultima(&max_dinheiro_gasto_ultima_run);

    int estado = estadoMenu;
    int menuOpcao = comprar;
    int itemOpcao = vida;
    int paginaDialogo = 0;
    bool sairLojaDaLoja = false;
    int confirmar_mouse;
    Rectangle hitbox_seta;

    hitbox_seta.x = 628.0f;
    hitbox_seta.y = 600.0f;
    hitbox_seta.width = 105.0f;
    hitbox_seta.height = 90.0f;

    while (IsMouseButtonDown(MOUSE_LEFT_BUTTON) == 1) {
        BeginDrawing();
        ClearBackground(BLACK);
        desenharCursor();
        EndDrawing();
    }

    while (sairLojaDaLoja == false && WindowShouldClose() == 0) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            clickCursor(true);
        } else {
            clickCursor(false);
        }

        if (IsKeyPressed(KEY_ESCAPE) == 1) {
            if (estado == estadoCompra || estado == estadoConversa) {
                estado = estadoMenu;
            }
        }

        confirmar_mouse = hitboxes_opcao_loja(&menuOpcao);
        if (estado == estadoMenu) {
            if (IsKeyPressed(KEY_DOWN) == 1 || IsKeyPressed(KEY_S) == 1) {
                menuOpcao++;
                if (menuOpcao > 2) {
                    menuOpcao = 0;
                }
            }

            if (IsKeyPressed(KEY_UP) == 1 || IsKeyPressed(KEY_W) == 1) {
                if (menuOpcao == 0) {
                    menuOpcao = 2;
                } else {
                    menuOpcao--;
                }
            }

            if (IsKeyPressed(KEY_ENTER) == 1) {
                if (menuOpcao == comprar) {
                    estado = estadoCompra;
                    itemOpcao = vida;
                } else if (menuOpcao == conversar) {
                    estado = estadoConversa;
                    paginaDialogo = 0;
                } else if (menuOpcao == sairLoja) {
                    sairLojaDaLoja = true;
                }
            }
        } if (estado == estadoCompra) {
            if (hitboxes_itens(&itemOpcao) == 1) {
                comprar_itens(personagem, itemOpcao);
            }
        } else if (estado == estadoConversa) {
            if (IsKeyPressed(KEY_ENTER) == 1) {
                if (paginaDialogo == 0) {
                    paginaDialogo = 1;
                } else {
                    estado = estadoMenu;
                }
            }

            if (CheckCollisionPointRec(GetMousePosition(), hitbox_seta) == 1) {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
                    if (paginaDialogo == 0) {
                        paginaDialogo = 1;
                    } else {
                        estado = estadoMenu;
                    }
                }
            }
        }

        if (confirmar_mouse == 1 && estado == estadoMenu) {
            if (menuOpcao == comprar) {
                estado = estadoCompra;
                itemOpcao = vida;
            } else if (menuOpcao == conversar) {
                estado = estadoConversa;
                paginaDialogo = 0;
            } else if (menuOpcao == sairLoja) {
                sairLojaDaLoja = true;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);

        Texture2D TexturaParaDesenhar;
        if (estado == estadoMenu) {
            if (menuOpcao == comprar) {
                TexturaParaDesenhar = texComprar;
            } else if (menuOpcao == conversar) {
                TexturaParaDesenhar = texConversar;
            } else {
                TexturaParaDesenhar = texsairLoja;
            }
        } else if (estado == estadoCompra) {
            if (itemOpcao == vida) {
                TexturaParaDesenhar = texCompraItem0;
            } else if (itemOpcao == mais2) {
                TexturaParaDesenhar = texCompraItem1;
            } else if (itemOpcao == menos2) {
                TexturaParaDesenhar = texCompraItem2;
            } else if (itemOpcao == mais4) {
                TexturaParaDesenhar = texCompraItem3;
            } else {
                TexturaParaDesenhar = texCompraItem4;
            }
        } else {
            if (paginaDialogo == 0) {
                TexturaParaDesenhar = texDialogo1;
            } else {
                TexturaParaDesenhar = texDialogo2;
            }
        }

        Rectangle original;
        Rectangle destino;
        Vector2 origem;

        original.x = 0.0f;
        original.y = 0.0f;
        original.width = TexturaParaDesenhar.width;
        original.height = TexturaParaDesenhar.height;
        destino.x = 0.0f;
        destino.y = 0.0f;
        destino.width = GetScreenWidth();
        destino.height = GetScreenHeight();
        origem.x = 0.0f;
        origem.y = 0.0f;

        DrawTexturePro(TexturaParaDesenhar, original, destino, origem, 0.0f, WHITE);

        if (estado == estadoConversa && paginaDialogo == 1) {
            DrawText(TextFormat("%d", max_dinheiro_gasto_ultima_run), 220, 330, 40,WHITE);
        }
        char *texto;
        texto = TextFormat("%d", dinheiro_total);
        DrawText(texto, 687, 1027, 45, WHITE);

        desenharCursor();
        EndDrawing();
    }
    UnloadTexture(texComprar);
    UnloadTexture(texConversar);
    UnloadTexture(texsairLoja);
    UnloadTexture(texCompraItem0);
    UnloadTexture(texCompraItem1);
    UnloadTexture(texCompraItem2);
    UnloadTexture(texCompraItem3);
    UnloadTexture(texCompraItem4);
    UnloadTexture(texDialogo1);
    UnloadTexture(texDialogo2);
}
