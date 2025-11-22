#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include "grafico.h"
#include "loads.h"
#include "jogo.h"
#include "cursor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

extern Texture2D texturas_final[6];
extern int final_loaded;

extern Texture2D textura_game_over_tente;
extern Texture2D textura_game_over_desisti;

void desenhar_frame_final(int indice_frame) {
    float tela_largura;
    float tela_altura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    tela_largura = GetScreenWidth();
    tela_altura = GetScreenHeight();

    if (indice_frame < 0) {
        indice_frame = 0;
    }
    if (indice_frame > 5) {
        indice_frame = 5;
    }

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = texturas_final[indice_frame].width;
    original.height = texturas_final[indice_frame].height;
    destino.x = 0.0f;
    destino.y = 0.0f;
    destino.width = tela_largura;
    destino.height = tela_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(texturas_final[indice_frame], original, destino, origem, 0.0f, WHITE);

    if (indice_frame == 5) {
        DrawText("Pressione ESC para sair", 20, 1040, 20, RAYWHITE);
    }
}

void desenhar_tela_game_over(int opcao) {
    float tela_largura;
    float tela_altura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;
    Texture2D textura_usar;

    tela_largura = GetScreenWidth();
    tela_altura = GetScreenHeight();

    if (opcao == 0) {
        textura_usar = textura_game_over_tente;
    } else {
        textura_usar = textura_game_over_desisti;
    }

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_usar.width;
    original.height = textura_usar.height;
    destino.x = 0.0f;
    destino.y = 0.0f;
    destino.width = tela_largura;
    destino.height = tela_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_usar, original, destino, origem, 0.0f, WHITE);
}

void desenhar_fundo(void) {
    float tela_largura;
    float tela_altura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    tela_largura = GetScreenWidth();
    tela_altura = GetScreenHeight();

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_fundo.width;
    original.height = textura_fundo.height;
    destino.x = 0.0f;
    destino.y = 0.0f;
    destino.width = tela_largura;
    destino.height = tela_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_fundo, original, destino, origem, 0.0f, WHITE);
}

void desenhar_baralho(void) {
    float baralho_largura;
    float baralho_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    baralho_largura = textura_baralho.width * escala_baralho;
    baralho_altura = textura_baralho.height * escala_baralho;

    x = 315;
    y = 200;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_baralho.width;
    original.height = textura_baralho.height;
    destino.x = x;
    destino.y = y;
    destino.width = baralho_largura;
    destino.height = baralho_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_baralho, original, destino, origem, 0.0f, WHITE);
}

void desenhar_carta(int x, int y, int largura, int altura, Carta *cart4) {
    Rectangle original;
    Rectangle destino;
    Vector2 origem;
    Texture2D textura_carta;
    int carta_loaded;
    int val;
    val = cart4->valor;

    if (val == 1) {
        textura_carta = textura_carta_a;
        carta_loaded = carta_a_loaded;
    } else if (val == 2) {
        textura_carta = textura_carta_2;
        carta_loaded = carta_2_loaded;
    } else if (val == 3) {
        textura_carta = textura_carta_3;
        carta_loaded = carta_3_loaded;
    } else if (val == 4) {
        textura_carta = textura_carta_4;
        carta_loaded = carta_4_loaded;
    } else if (val == 5) {
        textura_carta = textura_carta_5;
        carta_loaded = carta_5_loaded;
    } else if (val == 6) {
        textura_carta = textura_carta_6;
        carta_loaded = carta_6_loaded;
    } else if (val == 7) {
        textura_carta = textura_carta_7;
        carta_loaded = carta_7_loaded;
    } else if (val == 8) {
        textura_carta = textura_carta_8;
        carta_loaded = carta_8_loaded;
    } else if (val == 9) {
        textura_carta = textura_carta_9;
        carta_loaded = carta_9_loaded;
    } else if (val == 10) {
        textura_carta = textura_carta_10;
        carta_loaded = carta_10_loaded;
    } else if (val == 11) {
        textura_carta = textura_carta_j;
        carta_loaded = carta_j_loaded;
    } else if (val == 12) {
        textura_carta = textura_carta_q;
        carta_loaded = carta_q_loaded;
    } else {
        textura_carta = textura_carta_k;
        carta_loaded = carta_k_loaded;
    }

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_carta.width;
    original.height = textura_carta.height;
    destino.x = x;
    destino.y = y;
    destino.width = largura;
    destino.height = altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_carta, original, destino, origem, 0.0f, WHITE);
}

void desenhar_hand(Hand *hand, int x, int y, int hidden_first) {
    int carta_largura;
    int carta_altura;
    int gap;
    int start_x;
    int largura_total;

    if (hand == NULL) {
        return;
    }

    carta_largura = 150;
    carta_altura = 200;
    gap = 20;

    largura_total = 0;
    if (hand->quant > 0) {
        largura_total = hand->quant * (carta_largura + gap) - gap;
    }

    start_x = x - (largura_total / 2);

    for (int i = 0; i < hand->quant; i++) {
        int x_atual;
        int y_atual;
        x_atual = start_x + i * (carta_largura + gap);
        y_atual = y;

        if (i == 0 && hidden_first == 1) {
            Rectangle original;
            Rectangle destino;
            Vector2 origem;

            original.x = 0.0f;
            original.y = 0.0f;
            original.width = textura_carta_joker.width;
            original.height = textura_carta_joker.height;
            destino.x = x_atual;
            destino.y = y_atual;
            destino.width = carta_largura;
            destino.height = carta_altura;
            origem.x = 0.0f;
            origem.y = 0.0f;

            DrawTexturePro(textura_carta_joker, original, destino, origem, 0.0f, WHITE);
            continue;
        }
        desenhar_carta(x_atual, y_atual, carta_largura, carta_altura, hand->cartas[i]);
    }
}

void desenhar_bolsa(void) {
    float bolsa_largura;
    float bolsa_altura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    bolsa_largura = textura_bolsa.width * escala_bolsa;
    bolsa_altura = textura_bolsa.height * escala_bolsa;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_bolsa.width;
    original.height = textura_bolsa.height;
    destino.x = 0.0f;
    destino.y = 0.0f;
    destino.width = bolsa_largura;
    destino.height = bolsa_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_bolsa, original, destino, origem, 0.0f, WHITE);
}

void desenhar_vida_player(void) {
    int coracao_largura;
    int coracao_altura;
    int gap;
    int x;
    int y;
    int start_x_coracao;
    int start_y_coracao;
    int ang_diagonal;
    int i;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    coracao_largura = textura_coracao_vazio.width * escala_coracao;
    coracao_altura = textura_coracao_vazio.height * escala_coracao;
    gap = coracao_largura + 4.0f * escala_coracao;
    ang_diagonal = 4;

    x = 325;
    y = 900;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_vazio.width;
    original.height = textura_coracao_vazio.height;
    origem.x = 0.0f;
    origem.y = 0.0f;

    i = 0;
    while (i < player_vida_max) {
        start_x_coracao = x + i * gap;
        start_y_coracao = y + i * ang_diagonal;

        destino.x = start_x_coracao;
        destino.y = start_y_coracao;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_vazio, original, destino, origem, 0.0f, WHITE);
        i++;
    }
    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_cheio.width;
    original.height = textura_coracao_cheio.height;

    i = 0;
    while (i < player_vida) {
        start_x_coracao = x + i * gap;
        start_y_coracao = y + i * ang_diagonal;

        destino.x = start_x_coracao;
        destino.y = start_y_coracao;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_cheio, original, destino, origem, 0.0f, WHITE);
        i++;
    }
}

void desenhar_vida_player_hub(void) {
    int coracao_largura;
    int coracao_altura;
    int gap;
    int x;
    int y;
    int start_x_coracao;
    int start_y_coracao;
    int ang_diagonal;
    int i;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    coracao_largura = textura_coracao_vazio.width * escala_coracao;
    coracao_altura = textura_coracao_vazio.height * escala_coracao;
    gap = coracao_largura + 4.0f * escala_coracao;
    ang_diagonal = -2;

    x = 260;
    y = 35;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_vazio.width;
    original.height = textura_coracao_vazio.height;
    origem.x = 0.0f;
    origem.y = 0.0f;

    i = 0;
    while (i < player_vida_max) {
        start_x_coracao = x + i * gap;
        start_y_coracao = y + i * ang_diagonal;

        destino.x = start_x_coracao;
        destino.y = start_y_coracao;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_vazio, original, destino, origem, 0.0f, WHITE);
        i++;
    }
    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_cheio.width;
    original.height = textura_coracao_cheio.height;

    i = 0;
    while (i < player_vida) {
        start_x_coracao = x + i * gap;
        start_y_coracao = y + i * ang_diagonal;

        destino.x = start_x_coracao;
        destino.y = start_y_coracao;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_cheio, original, destino, origem, 0.0f, WHITE);
        i++;
    }
}

void desenhar_vida_dealer(int vida, int vida_max) {
    int coracao_largura;
    int coracao_altura;
    int gap;
    int por_linha;
    int linha;
    int coluna;
    int x;
    int y;
    int start_x;
    int start_y;
    int i;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    if (vida < 0) {
        vida = 0;
    }
    if (vida > vida_max) {
        vida = vida_max;
    }

    coracao_largura = textura_coracao_vazio.width * escala_coracao;
    coracao_altura = textura_coracao_vazio.height * escala_coracao;
    gap = coracao_largura + 2.0f * escala_coracao;

    por_linha = 5;
    x = 1450;
    y = 70;

    origem.x = 0.0f;
    origem.y = 0.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_vazio.width;
    original.height = textura_coracao_vazio.height;

    i = 0;
    while (i < vida_max) {
        linha = i / por_linha;
        coluna = i % por_linha;

        start_x = x + coluna * gap;
        start_y = y + linha * coracao_altura;

        destino.x = start_x;
        destino.y = start_y;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_vazio, original, destino, origem, 0.0f, WHITE);
        i++;
    }

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_coracao_cheio.width;
    original.height = textura_coracao_cheio.height;

    i = 0;
    while (i < vida) {
        linha = i / por_linha;
        coluna = i % por_linha;

        start_x = x + coluna * gap;
        start_y = y + linha * coracao_altura;

        destino.x = start_x;
        destino.y = start_y;
        destino.width = coracao_largura;
        destino.height = coracao_altura;

        DrawTexturePro(textura_coracao_cheio, original, destino, origem, 0.0f, WHITE);
        i++;
    }
}

int baralho_hitbox(void) {
    Vector2 mouse;
    Rectangle area_baralho;
    int hover;
    int x;
    int y;
    int baralho_largura;
    int baralho_altura;

    x = 840;
    y = 420;
    baralho_largura = 170;
    baralho_altura = 190;

    mouse = GetMousePosition();
    area_baralho.x = x;
    area_baralho.y = y;
    area_baralho.width = baralho_largura;
    area_baralho.height = baralho_altura;
    hover = CheckCollisionPointRec(mouse, area_baralho);

    if (hover == 1) {
        if (GetTime() >= rodada_travada) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
                if (game_state == estado_player) {
                    player_hitou();
                    return 2;
                }
            }
        }
        return 1;
    }

    return 0;
}

int stand_hitbox(void) {
    Vector2 mouse;
    Rectangle stand_area;
    int hover;
    int stand_x;
    int stand_y;
    int stand_largura;
    int stand_altura;

    stand_x = 1380;
    stand_y = 700;
    stand_largura = 500;
    stand_altura = 250;

    mouse = GetMousePosition();
    stand_area.x = stand_x;
    stand_area.y = stand_y;
    stand_area.width = stand_largura;
    stand_area.height = stand_altura;
    hover = CheckCollisionPointRec(mouse, stand_area);

    if (hover == 1) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
            if (game_state == estado_player) {
                player_stand();
                return 2;
            }
        }
        return 1;
    }

    return 0;
}

void desenhar_inventario(void) {
    float inv_largura;
    float inv_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    inv_largura = textura_inventario.width * inventario_escala;
    inv_altura = textura_inventario.height * inventario_escala;

    x = -170.0f;
    y = 70.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_inventario.width;
    original.height = textura_inventario.height;
    destino.x = x;
    destino.y = y;
    destino.width = inv_largura;
    destino.height = inv_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_inventario, original, destino, origem, 0.0f, WHITE);
}

int abrir_inventario(void) {
    Vector2 mouse;
    Rectangle area;
    int hover;
    int clicou;
    int resultado;
    int x;
    int y;
    int largura;
    int altura;

    x = 70;
    y = 810;
    largura = 200;
    altura = 200;

    mouse = GetMousePosition();
    area.x = x;
    area.y = y;
    area.width = largura;
    area.height = altura;

    if (CheckCollisionPointRec(mouse, area) == 1) {
        hover = 1;
    } else {
        hover = 0;
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
        clicou = 1;
    } else {
        clicou = 0;
    }

    if (hover == 1 && clicou == 1) {
        if (inv_open == 1) {
            inv_open = 0;
        } else {
            inv_open = 1;
        }
        resultado = 2;
    } else if (hover == 1) {
        resultado = 1;
    } else {
        resultado = 0;
    }

    return resultado;
}

void criar_hurtbox(void) {
    int x;
    int y;
    int tamanho;
    Rectangle hurtbox_inimigo;
    Rectangle area_ataque;

    x = 880;
    y = 70;
    tamanho = 120;

    hurtbox_inimigo.x = x;
    hurtbox_inimigo.y = y;
    hurtbox_inimigo.width = tamanho;
    hurtbox_inimigo.height = tamanho;

    if (ataque_ativo == 1) {
        area_ataque.x = ataque_centro_x - raio_ataque;
        area_ataque.y = ataque_centro_y - raio_ataque;
        area_ataque.width = raio_ataque * 2.0f;
        area_ataque.height = raio_ataque * 2.0f;

        if (CheckCollisionRecs(hurtbox_inimigo, area_ataque) == true) {
            if (fase_atual != NULL) {
                if (fase_atual->vida > 0) {
                    fase_atual->vida = fase_atual->vida - ataque_dano;
                    if (fase_atual->vida < 0) {
                        fase_atual->vida = 0;
                    }
                }
            }

            ataque_ativo = 0;

            estado_atual = estado_resultado;
            game_state = estado_resultado;
            fugir_ou_n = 1;
        }
    }
}

void iniciar_ataque_normal(void) {
    if (ataque_ativo == 1) {
        return;
    }
    ataque_inix = 880.0f;
    ataque_iniy = 580.0f;
    ataque_fimx = 880.0f;
    ataque_fimy = 70.0f;
    ataque_comecou = GetTime();
    ataque_duracao = 0.60f;
    ataque_tipo = 0;
    ataque_dano = 1;
    raio_ataque = 26.0f;
    ataque_centro_x = ataque_inix;
    ataque_centro_y = ataque_iniy;
    ataque_ativo = 1;
}

void iniciar_ataque_blackjack(void) {
    if (ataque_ativo == 1) {
        return;
    }
    ataque_inix = 880.0f;
    ataque_iniy = 580.0f;
    ataque_fimx = 880.0f;
    ataque_fimy = 70.0f;
    ataque_comecou = GetTime();
    ataque_duracao = 0.60f;
    ataque_tipo = 1;
    ataque_dano = 2;
    raio_ataque = 28.0f;
    ataque_centro_x = ataque_inix;
    ataque_centro_y = ataque_iniy;
    ataque_ativo = 1;
}

void atualizar_ataque(void) {
    double t0;
    double t;
    float x0;
    float y0;
    float x1;
    float y1;

    if (ataque_ativo == 0) {
        return;
    }

    t0 = GetTime() - ataque_comecou;
    t = t0 / ataque_duracao;

    if (t < 0.0) {
        t = 0.0;
    }
    if (t > 1.0) {
        t = 1.0;
    }

    x0 = ataque_inix;
    y0 = ataque_iniy;
    x1 = ataque_fimx;
    y1 = ataque_fimy;

    ataque_centro_x = x0;
    ataque_centro_y = y0 + (y1 - y0) * t;

    if (t >= 1.0) {
        ataque_ativo = 0;
    }
}

void desenhar_menu_resultado(void) {
    if (opcao_pos_vitoria == 0) {
        desenhar_continuar();
    } else {
        desenhar_fugir();
    }
}

void desenhar_vitoria(void) {
    float vitoria_largura;
    float vitoria_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    vitoria_largura = textura_vitoria.width * escala_vitoria;
    vitoria_altura = textura_vitoria.height * escala_vitoria;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_vitoria.width;
    original.height = textura_vitoria.height;
    destino.x = x;
    destino.y = y;
    destino.width = vitoria_largura;
    destino.height = vitoria_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_vitoria, original, destino, origem, 0.0f, WHITE);
    desenhar_menu_resultado();
}

void desenhar_vitoria21(void) {
    float vitoria21_largura;
    float vitoria21_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    vitoria21_largura = textura_vitoria21.width * escala_vitoria21;
    vitoria21_altura = textura_vitoria21.height * escala_vitoria21;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_vitoria21.width;
    original.height = textura_vitoria21.height;
    destino.x = x;
    destino.y = y;
    destino.width = vitoria21_largura;
    destino.height = vitoria21_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_vitoria21, original, destino, origem, 0.0f, WHITE);
    desenhar_menu_resultado();
}

void desenhar_derrota(void) {
    float derrota_largura;
    float derrota_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    derrota_largura = textura_derrota.width * escala_derrota;
    derrota_altura = textura_derrota.height * escala_derrota;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_derrota.width;
    original.height = textura_derrota.height;
    destino.x = x;
    destino.y = y;
    destino.width = derrota_largura;
    destino.height = derrota_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_derrota, original, destino, origem, 0.0f, WHITE);
    desenhar_menu_resultado();
}

void desenhar_empate(void) {
    float empate_largura;
    float empate_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    empate_largura = textura_empate.width * escala_empate;
    empate_altura = textura_empate.height * escala_empate;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_empate.width;
    original.height = textura_empate.height;
    destino.x = x;
    destino.y = y;
    destino.width = empate_largura;
    destino.height = empate_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_empate, original, destino, origem, 0.0f, WHITE);
    desenhar_menu_resultado();
}

void desenhar_continuar(void) {
    float continuar_largura;
    float continuar_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    continuar_largura = textura_continuar.width * escala_continuar;
    continuar_altura = textura_continuar.height * escala_continuar;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_continuar.width;
    original.height = textura_continuar.height;
    destino.x = x;
    destino.y = y;
    destino.width = continuar_largura;
    destino.height = continuar_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_continuar, original, destino, origem, 0.0f, WHITE);
}

void desenhar_fugir(void) {
    float fugir_largura;
    float fugir_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    fugir_largura = textura_fugir.width * escala_fugir;
    fugir_altura = textura_fugir.height * escala_fugir;

    x = 500.0f;
    y = 20.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_fugir.width;
    original.height = textura_fugir.height;
    destino.x = x;
    destino.y = y;
    destino.width = fugir_largura;
    destino.height = fugir_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_fugir, original, destino, origem, 0.0f, WHITE);
}

int hitboxes_fugir_batalha(int *opcao_pos_vitoria) {
    Rectangle hitbox_continuar;
    Rectangle hitbox_sair;
    Vector2 mouse_pos;
    int mouse_continuar;
    int mouse_sair;
    int confirmar;

    hitbox_continuar.x = 750.0f;
    hitbox_continuar.y = 275.0f;
    hitbox_continuar.width = 300.0f;
    hitbox_continuar.height = 45.0f;

    hitbox_sair.x = 750.0f;
    hitbox_sair.y = 370.0f;
    hitbox_sair.width = 300.0f;
    hitbox_sair.height = 45.0f;

    mouse_pos = GetMousePosition();
    mouse_continuar = 0;
    mouse_sair = 0;
    confirmar = 0;

    if (CheckCollisionPointRec(mouse_pos, hitbox_continuar) == 1) {
        mouse_continuar = 1;
    }

    if (CheckCollisionPointRec(mouse_pos, hitbox_sair) == 1) {
        mouse_sair = 1;
    }

    if (opcao_pos_vitoria != NULL) {
        if (mouse_continuar == 1) {
            *opcao_pos_vitoria = 0;
        }

        if (mouse_sair == 1) {
            *opcao_pos_vitoria = 1;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
        if (mouse_continuar == 1 || mouse_sair == 1) {
            confirmar = 1;
        }
    }

    return confirmar;
}

int hitboxes_trinkets_inventario(int *trinket_selecionado) {
    Rectangle hitbox_mais2;
    Rectangle hitbox_menos2;
    Rectangle hitbox_mais4;
    Rectangle hitbox_menos4;
    Vector2 mouse_pos;
    int mouse_mais2;
    int mouse_menos2;
    int mouse_mais4;
    int mouse_menos4;
    int confirmar;

    hitbox_mais2.x = 150.0f;
    hitbox_mais2.y = 175.0f;
    hitbox_mais2.width = 130.0f;
    hitbox_mais2.height = 130.0f;

    hitbox_menos2.x = 340.0f;
    hitbox_menos2.y = 175.0f;
    hitbox_menos2.width = 130.0f;
    hitbox_menos2.height = 130.0f;

    hitbox_mais4.x = 150.0f;
    hitbox_mais4.y = 320.0f;
    hitbox_mais4.width = 130.0f;
    hitbox_mais4.height = 130.0f;

    hitbox_menos4.x = 340.0f;
    hitbox_menos4.y = 320.0f;
    hitbox_menos4.width = 130.0f;
    hitbox_menos4.height = 130.0f;

    mouse_pos = GetMousePosition();
    mouse_mais2 = 0;
    mouse_menos2 = 0;
    mouse_mais4 = 0;
    mouse_menos4 = 0;
    confirmar = 0;

    if (CheckCollisionPointRec(mouse_pos, hitbox_mais2) == 1) {
        mouse_mais2 = 1;
    }

    if (CheckCollisionPointRec(mouse_pos, hitbox_menos2) == 1) {
        mouse_menos2 = 1;
    }

    if (CheckCollisionPointRec(mouse_pos, hitbox_mais4) == 1) {
        mouse_mais4 = 1;
    }

    if (CheckCollisionPointRec(mouse_pos, hitbox_menos4) == 1) {
        mouse_menos4 = 1;
    }

    if (trinket_selecionado != NULL) {
        if (mouse_mais2 == 1) {
            *trinket_selecionado = 0;
        }

        if (mouse_menos2 == 1) {
            *trinket_selecionado = 1;
        }

        if (mouse_mais4 == 1) {
            *trinket_selecionado = 2;
        }

        if (mouse_menos4 == 1) {
            *trinket_selecionado = 3;
        }
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
        if (mouse_mais2 == 1 || mouse_menos2 == 1 || mouse_mais4 == 1 || mouse_menos4 == 1) {
            confirmar = 1;
        }
    }

    return confirmar;
}

void desenhar_trinkets_inventario(void) {
    Rectangle original;
    Rectangle destino;
    Vector2 origem;

    origem.x = 0.0f;
    origem.y = 0.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_trinket_mais2.width;
    original.height = textura_trinket_mais2.height;
    destino.x = 150.0f;
    destino.y = 175.0f;
    destino.width = 130.0f;
    destino.height = 130.0f;
    
    DrawTexturePro(textura_trinket_mais2, original, destino, origem, 0.0f, WHITE);

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_trinket_menos2.width;
    original.height = textura_trinket_menos2.height;
    destino.x = 340.0f;
    destino.y = 175.0f;
    destino.width = 130.0f;
    destino.height = 130.0f;

    DrawTexturePro(textura_trinket_menos2, original, destino, origem, 0.0f, WHITE);

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_trinket_mais4.width;
    original.height = textura_trinket_mais4.height;
    destino.x = 150.0f;
    destino.y = 320.0f;
    destino.width = 130.0f;
    destino.height = 130.0f;

    DrawTexturePro(textura_trinket_mais4, original, destino, origem, 0.0f, WHITE);

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_trinket_menos4.width;
    original.height = textura_trinket_menos4.height;
    destino.x = 340.0f;
    destino.y = 320.0f;
    destino.width = 130.0f;
    destino.height = 130.0f;

    DrawTexturePro(textura_trinket_menos4, original, destino, origem, 0.0f, WHITE);
}

void desenhar_stand(void) {
    float stand_largura;
    float stand_altura;
    float x;
    float y;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;
    
    stand_largura = textura_stand.width * escala_stand;
    stand_altura = textura_stand.height * escala_stand;

    x = 1350.0f;
    y = 665.0f;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura_stand.width;
    original.height = textura_stand.height;
    destino.x = x;
    destino.y = y;
    destino.width = stand_largura;
    destino.height = stand_altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(textura_stand, original, destino, origem, 0.0f, WHITE);
}

void desenhar_quant_trinkets(void) {
    DrawText(TextFormat("%d", trinket_mais2_count), 160, 182, 24, BLACK);
    DrawText(TextFormat("%d", trinket_menos2_count), 350, 192, 24, BLACK);
    DrawText(TextFormat("%d", trinket_mais4_count), 160, 330, 24, BLACK);
    DrawText(TextFormat("%d", trinket_menos4_count), 350, 330, 24, BLACK);
}
