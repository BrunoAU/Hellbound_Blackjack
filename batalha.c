#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include "grafico.h"
#include "loads.h"
#include "jogo.h"
#include "hub.h"
#include "fases.h"
#include "batalha.h"
#include "stats.h"
#include "cursor.h"
#include "ataque.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern int dificuldade;
extern int voltar_menu;

void desenhar_frame_final(int indice_frame);
void desenhar_tela_game_over(int opcao);

int continuar_habilitado = 1;

int personagem_maga = 0;
int cura_maga_aplicada = 0;
int dealer_ultima_vida = -1;
int arqueiro_trinket_dado = 0;

int ultimo_ataque_ativo = 0;
int opcao_game_over = 0;

void TelaFimDeJogo(void) {
    int frame_atual;
    double tempo_acumulado;
    double tempo_por_frame;
    double tempo_inicio;
    double tempo_decorrido;
    frame_atual = 0;
    tempo_acumulado = 0.0;
    tempo_por_frame = 0.25;
    tempo_inicio = GetTime();

    while (WindowShouldClose() == 0) {
        tempo_decorrido = GetTime() - tempo_inicio;
        if (tempo_decorrido >= 4.0) {
            voltar_menu = 1;
            break;
        }

        if (frame_atual < 5) {
            tempo_acumulado = tempo_acumulado + GetFrameTime();
            if (tempo_acumulado >= tempo_por_frame) {
                frame_atual++;
                tempo_acumulado = 0.0;
            }
        }
        BeginDrawing();
        ClearBackground(BLACK);
        desenhar_frame_final(frame_atual);
        EndDrawing();
    }
}

void preparar_turno_player(int *rodada_iniciada) {
    if (estado_atual == estado_batalha) {
        game_state = estado_player;
        rodada_travada = GetTime() + 0.20f;

        if (rodada_iniciada != NULL) {
            *rodada_iniciada = 1;
        }

        continuar_habilitado = 1;
        cura_maga_aplicada = 0;

        if (fase_atual != NULL) {
            dealer_ultima_vida = fase_atual->vida;
        } else {
            dealer_ultima_vida = -1;
        }
    }
}

void desenhar_hud_basica(void) {
    int esconder_primeira;
    int dealer_vida;
    int dealer_vida_max;
    int total_player;
    int total_dealer;
    int as_11_1_player;
    int as_11_1_dealer;
    int total_dealer_visivel;

    desenhar_fundo();
    desenhar_baralho();
    desenhar_stand();
    desenhar_bolsa();
    abrir_inventario();
    baralho_hitbox();
    stand_hitbox();
    desenhar_vida_player();
    
    dealer_vida = fase_atual->vida;
    dealer_vida_max = fase_atual->vida_max;
    if (dealer_vida > dealer_vida_max) {
        dealer_vida = dealer_vida_max;
    }
    desenhar_vida_dealer(dealer_vida, dealer_vida_max);

    esconder_primeira = 0;
    if (game_state == estado_player) {
        esconder_primeira = 1;
    }

    desenhar_hand(&dealer_hand, 960, 75, esconder_primeira);
    desenhar_hand(&player_hand, 960, 770, 0);

    as_11_1_player = 0;
    as_11_1_dealer = 0;
    total_player = valor_com_as(&player_hand, &as_11_1_player) + trinket_bonus_player;
    total_dealer = valor_com_as(&dealer_hand, &as_11_1_dealer) + trinket_bonus_dealer;
    total_dealer_visivel = total_dealer;

    if (game_state == estado_player) {
        if (dealer_hand.quant > 0) {
            Carta *primeira;
            int valor_primeira;
            primeira = dealer_hand.cartas[0];
            if (primeira != NULL) {
                valor_primeira = valor_carta(primeira);
                total_dealer_visivel = total_dealer - valor_primeira;
            }
        }
    }
    DrawText(TextFormat("Player: %d", total_player), 40, 680, 26, RAYWHITE);
    DrawText(TextFormat("Dealer: %d", total_dealer_visivel), 1200, 30, 26, RAYWHITE);

    if (resultado_msg[0] != '\0') {
        DrawText(resultado_msg, 24, 60, 30, RAYWHITE);
    }
}

void dealer_turno(void) {
    int as_11_1_dealer;
    int as_11_1_player;
    int val_dealer;
    int val_player;
    int deve_puxar;

    if (game_state != estado_dealer) {
        return;
    }
    if (GetTime() < dealer_prox_acao) {
        return;
    }

    as_11_1_dealer = 0;
    as_11_1_player = 0;
    val_player = valor_com_as(&player_hand, &as_11_1_player) + trinket_bonus_player;
    val_dealer = valor_com_as(&dealer_hand, &as_11_1_dealer) + trinket_bonus_dealer;
    deve_puxar = dealerDevePuxar(val_dealer, as_11_1_dealer, val_player);

    if (deve_puxar == 1) {
        puxar_para_mao(&dealer_hand);
        dealer_prox_acao = GetTime() + delay_do_dealer;
        return;
    }

    estado_atual = estado_resultado;
    game_state = estado_resultado;
    comparacao_final();

    if (resultado_aplicado == 0) {
        game_state = estado_parado;
        continuar_habilitado = 1;
        rodada_travada = GetTime() + 0.20;
    }
    return;
}

void TelaBatalha(Personagem personagem) {
    int rodada_iniciada;
    int pode_iniciar_rodada;
    int confirmar_menu;
    int fugiu_para_hub;

    fugiu_para_hub = 0;
    estado_atual = estado_batalha;
    game_state = estado_parado;
    resultado_msg[0] = '\0';
    last_win = 0;
    ataque_ativo = 0;
    inv_count = 0;
    inv_open = 0;
    player_vida_max = personagem.coracoes;
    historico_batalha_salvo = 0;

    SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    HideCursor();
    SetRandomSeed((unsigned int) time(NULL));

    load_golpes();
    load_tudo();

    init_baralho();
    hand_clear(&player_hand);
    hand_clear(&dealer_hand);

    if (fugido == 0) {
        player_vida = player_vida_max;
    } else {
        if (player_vida > player_vida_max) {
            player_vida = player_vida_max;
        }
    }

    if (player_vida <= 0) {
        game_over = 1;
        last_win = 0;
        estado_atual = estado_resultado;
        resultado_msg[0] = '\0';
        if (historico_batalha_salvo == 0) {
            registrar_resultado_batalha(0);
            historico_batalha_salvo = 1;
        }
    }

    personagem_maga = 0;
    if (personagem.nome != NULL) {
        if (strcmp(personagem.nome, "Maga") == 0) {
            personagem_maga = 1;
        } else if (strcmp(personagem.nome, "Arqueiro") == 0) {
            if (arqueiro_trinket_dado == 0) {
                trinket_mais2_count++;
                if (trinket_mais2_count < 0) {
                    trinket_mais2_count = 0;
                }
                arqueiro_trinket_dado = 1;
            }
        }
    }

    inv_count = 0;
    inv_count = inv_count + trinket_mais2_count;
    inv_count = inv_count + trinket_mais4_count;
    inv_count = inv_count + trinket_menos2_count;
    inv_count = inv_count + trinket_menos4_count;

    cura_maga_aplicada = 0;
    rodada_travada = 0.0;
    fugir_ou_n = 0;
    menu_fuga_iniciado = 0;
    opcao_pos_vitoria = 0;
    espera_menu_fugir = 0.0;
    venceu_todas = 0;
    opcao_game_over = 0;
    voltar_menu = 0;

    if (fase_head == NULL) {
        fase_head = criar_fases_encadeadas(dificuldade);
        reiniciar_fases();
    } else {
        if (fase_atual == NULL) {
            fase_atual = fase_head;
        }

        if (fase_atual->vida > fase_atual->vida_max) {
            fase_atual->vida = fase_atual->vida_max;
        }
    }
    
    pode_iniciar_rodada = 1;
    continuar_habilitado = 1;

    if (fase_atual != NULL) {
        dealer_ultima_vida = fase_atual->vida;
    } else {
        dealer_ultima_vida = -1;
    }

    opcao_pos_vitoria = 0;
    menu_fuga_iniciado = 0;
    ultimo_ataque_ativo = ataque_ativo;

    while (WindowShouldClose() == 0) {
        int pular_para_desenho;
        pular_para_desenho = 0;
        rodada_iniciada = 0;
        confirmar_menu = 0;

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == 1) {
            clickCursor(1);
        } else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) == 1) {
            clickCursor(0);
        }

        if (IsKeyPressed(KEY_F11) == 1) {
            ToggleFullscreen();
        }
        
        if (game_over == 1) {
            if (historico_batalha_salvo == 0) {
                registrar_resultado_batalha(0);
                historico_batalha_salvo = 1;
            }

            if (IsKeyPressed(KEY_UP) == 1 || IsKeyPressed(KEY_W) == 1) {
                opcao_game_over = 0;
            }
            if (IsKeyPressed(KEY_DOWN) == 1 || IsKeyPressed(KEY_S) == 1) {
                opcao_game_over = 1;
            }
            if (IsKeyPressed(KEY_ENTER) == 1) {
                if (opcao_game_over == 0) {
                    voltar_menu = 1;
                    break;
                } else {
                    unload_tudo();
                    unload_golpes();
                    CloseWindow();
                    exit(0);
                }
            }
            BeginDrawing();
            ClearBackground(BLACK);
            desenhar_tela_game_over(opcao_game_over);
            EndDrawing();
            continue;
        }

        if (estado_atual == estado_resultado) {
            pode_iniciar_rodada = 1;
            continuar_habilitado = 1;
            game_state = estado_parado;
        }
        
        if (rodada_iniciada == 0 && GetTime() >= rodada_travada) {
            if (pode_iniciar_rodada == 1 && (game_state == estado_parado || estado_atual == estado_resultado) && fugir_ou_n == 0) {
                if (pular_para_desenho == 0) {
                    trinket_bonus_player = 0;
                    trinket_bonus_dealer = 0;
                    resultado_msg[0] = '\0';
                    ataque_ativo = 0;

                    start_battle();

                    if (estado_atual == estado_batalha) {
                        preparar_turno_player(&rodada_iniciada);
                        pode_iniciar_rodada = 0;
                    } else {
                        pode_iniciar_rodada = 1;
                        game_state = estado_parado;
                        continuar_habilitado = 1;
                    }
                }
            }
        }

        if (pular_para_desenho == 0) {
            if (estado_atual == estado_resultado && fugir_ou_n == 1) {
                if (menu_fuga_iniciado == 0) {
                    opcao_pos_vitoria = 0;
                    menu_fuga_iniciado = 1;
                }
            }

            if (game_state == estado_dealer) {
                dealer_turno();
            }

            if (game_state == estado_resultado && fugir_ou_n == 0) {
                fugir_ou_n = 1;
                menu_fuga_iniciado = 1;
                opcao_pos_vitoria = 0;
            }

            if (personagem_maga == 1 && fase_atual != NULL) {
                if (fase_atual->vida < dealer_ultima_vida && cura_maga_aplicada == 0) {
                    player_vida++;
                    if (player_vida > player_vida_max) {
                        if (player_vida_max < 5) {
                            player_vida_max = player_vida;
                            if (player_vida_max > 5) {
                                player_vida_max = 5;
                            }
                        }
                    }

                    if (player_vida > player_vida_max) {
                        player_vida = player_vida_max;
                    }
                    if (player_vida > 5) {
                        player_vida = 5;
                    }
                    cura_maga_aplicada = 1;
                }
                dealer_ultima_vida = fase_atual->vida;
            }
        }

        if (ataque_ativo == 1 && ultimo_ataque_ativo == 0) {
            iniciar_golpe();
        }
        ultimo_ataque_ativo = ataque_ativo;

        if (fugiu_para_hub == 1) {
            break;
        }
        atualizar_golpe();

        BeginDrawing();
        ClearBackground(BLACK);
        desenhar_hud_basica();

        if (estado_atual == estado_resultado) {
            if (last_win == 0 || last_win == 2) {
                desenhar_derrota();
            } else if (last_win == 1) {
                int total_player;
                int as_11_1_player;
                as_11_1_player = 0;
                total_player = valor_com_as(&player_hand, &as_11_1_player) + trinket_bonus_player;

                if (total_player == 21) {
                    desenhar_vitoria21();
                } else {
                    desenhar_vitoria();
                }
            } else if (last_win == 3) {
                desenhar_empate();
            }

            if (espera_menu_fugir <= 0.0 || GetTime() >= espera_menu_fugir) {
                if (fugir_ou_n == 1 || last_win == 0 || last_win == 2 || last_win == 3) {
                    fugir_ou_n = 1;
                    menu_fuga_iniciado = 1;
                    confirmar_menu = hitboxes_fugir_batalha(&opcao_pos_vitoria);
                    if (confirmar_menu == 1) {
                        if (opcao_pos_vitoria == 1) {
                            game_state = estado_parado;
                            trinket_bonus_player = 0;
                            trinket_bonus_dealer = 0;
                            ataque_ativo = 0;
                            if (fase_atual != NULL) {
                                if (fase_atual->vida <= 0) {
                                    if (fase_atual->next != NULL) {
                                        fase_atual = fase_atual->next;
                                    } else {
                                        venceu_todas = 1;
                                    }
                                }

                                if (fase_atual->vida_max > 0) {
                                    fase_atual->vida = fase_atual->vida_max;
                                } else {
                                    fase_atual->vida = 1;
                                }
                            }
                            fugido = 1;
                            fugiu_para_hub = 1;
                            pular_para_desenho = 1;
                        } else {
                            if (fugiu_para_hub == 0 && continuar_habilitado == 1) {
                                continuar_habilitado = 0;
                                fugir_ou_n = 0;
                                menu_fuga_iniciado = 0;
                                rodada_travada = GetTime() + 0.5;
                                if (fase_atual != NULL && fase_atual->vida <= 0) {
                                    if (fase_atual->next != NULL) {
                                        fase_atual = fase_atual->next;

                                        if (fase_atual->vida_max > 0) {
                                            fase_atual->vida = fase_atual->vida_max;
                                        } else {
                                            fase_atual->vida = 1;
                                        }
                                        trinket_bonus_player = 0;
                                        trinket_bonus_dealer = 0;
                                        resultado_msg[0] = '\0';
                                        ataque_ativo = 0;

                                        start_battle();

                                        if (estado_atual == estado_batalha) {
                                            preparar_turno_player(NULL);
                                            pode_iniciar_rodada = 0;
                                        } else {
                                            pode_iniciar_rodada = 1;
                                            game_state = estado_parado;
                                            continuar_habilitado = 1;
                                        }
                                    } else {
                                        venceu_todas = 1;
                                        if (historico_batalha_salvo == 0) {
                                            registrar_resultado_batalha(1);
                                            historico_batalha_salvo = 1;
                                        }
                                        TelaFimDeJogo();
                                        strcpy(resultado_msg, "Voce venceu todas as fases!");
                                        pode_iniciar_rodada = 1;
                                        game_state = estado_parado;
                                        continuar_habilitado = 1;
                                        fugiu_para_hub = 1;
                                    }
                                } else {
                                    trinket_bonus_player = 0;
                                    trinket_bonus_dealer = 0;
                                    resultado_msg[0] = '\0';
                                    ataque_ativo = 0;

                                    start_battle();

                                    if (estado_atual == estado_batalha) {
                                        preparar_turno_player(NULL);
                                        pode_iniciar_rodada = 0;
                                    } else {
                                        pode_iniciar_rodada = 1;
                                        game_state = estado_parado;
                                        continuar_habilitado = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        atualizar_ataque();
        criar_hurtbox();
        desenhar_golpe();

        if (inv_open == 1) {
            desenhar_inventario();
            desenhar_trinkets_inventario();
            desenhar_quant_trinkets();

            int trinket_selecionado;
            int clicou_trinket;
            clicou_trinket = hitboxes_trinkets_inventario(&trinket_selecionado);
            if (clicou_trinket == 1) {
                if (trinket_selecionado == 0) {
                    usar_trinket_mais2();
                } else if (trinket_selecionado == 1) {
                    usar_trinket_menos2();
                } else if (trinket_selecionado == 2) {
                    usar_trinket_mais4();
                } else if (trinket_selecionado == 3) {
                    usar_trinket_menos4();
                }
            }
        }
        Font fonte;
        Vector2 posicao;
        Vector2 origem;
        float tamanho;
        float espaco;
        float ang;
        const char *texto;
        fonte = GetFontDefault();
        posicao.x = 340.0f;
        posicao.y = 960.0f;
        origem.x = 0.0f;
        origem.y = 0.0f;
        tamanho = 30.0f;
        espaco = 1.0f;
        ang = 4.0f;
        texto = TextFormat("y$: %d", dinheiro_total);
        DrawTextPro(fonte, texto, posicao, origem, ang, tamanho, espaco, BLACK);

        desenharCursor();
        EndDrawing();
    }

    if (voltar_menu == 1) {
        reiniciar_fases();
        destruir_fases(fase_head);
        dinheiro_total = 0;
        trinket_mais2_count = 0;
        trinket_menos2_count = 0;
        trinket_mais4_count = 0;
        trinket_menos4_count = 0;
        trinket_bonus_player = 0;
        trinket_bonus_dealer = 0;
        game_over = 0;
        fugido = 0;
        venceu_todas = 0;
        arqueiro_trinket_dado = 0;
        opcao_game_over = 0;

        return;
    }

    if (fugiu_para_hub == 1) {
        estado_atual = estado_mapa;
        game_state = estado_parado;
        continuar_habilitado = 1;

        TelaHub(personagem);
        return;
    }
}
