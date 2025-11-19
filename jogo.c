#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include "grafico.h"
#include "jogo.h"
#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int first_hand_blackjack(Hand *hand) {
    if (hand == NULL) {
        return 0;
    }
    if (hand->quant != 2) {
        return 0;
    }
    int tem_as_11_1 = 0;
    int total = valor_com_as(hand, &tem_as_11_1);
    if (total == 21) {
        if (tem_as_11_1 == 1) {
            return 1;
        }
    }
    return 0;
}

int hand_bustou(Hand *hand) {
    if (hand == NULL) {
        return 0;
    }
    int as_11_1 = 0;
    int val = valor_com_as(hand, &as_11_1);

    if (val > 21) {
        return 1;
    } else {
        return 0;
    }
}

void fim_round(char *msg) {
    estado_atual = estado_resultado;

    strncpy(resultado_msg, msg, sizeof(resultado_msg) - 1);
    resultado_msg[sizeof(resultado_msg) - 1] = '\0';
    printf("%s\n", resultado_msg);
}

void player_ganhou(char *msg) {
    int as_11_1 = 0;
    int total = 0;
    last_win = 1;
    estado_atual = estado_resultado;
    fim_round(msg);

    total = valor_com_as(&player_hand, &as_11_1) + trinket_bonus_player;

    if (game_over == 0) {
        if (total == 21) {
            if (ataque_ativo == 0) {
                iniciar_ataque_blackjack();
            }
        } else {
            if (ataque_ativo == 0) {
                iniciar_ataque_normal();
            }
        }
    }
}

void empate(char *msg) {
    last_win = 3;
    fim_round(msg);
}

void dealer_ganhou(char *msg) {
    int as_11_1;
    int dealer_total;
    int dano;

    as_11_1 = 0;
    dealer_total = 0;
    dano = 1;

    last_win = 2;
    fim_round(msg);

    recompensa_aplicada = 1;

    dealer_total = valor_com_as(&dealer_hand, &as_11_1);
    if (dealer_total == 21) {
        dano = 2;
    }

    if (game_over == 0) {
        player_vida -= dano;
        if (player_vida <= 0) {
            player_vida = 0;
            game_over = 1;
        }
    }
}

int dealerDevePuxar(int dealer_val, int as_11_1, int player_val) {
    if (player_val > 21) {
        return 0;
    }
    if (dealer_val == 21) {
        return 0;
    }
    if (dealer_val >= 18 && dealer_val >= player_val) {
        return 0;
    }
    if (dealer_val < 17) {
        return 1;
    }
    if (dealer_val == 17 && as_11_1 == 1) {
        if (player_val <= 17) {
            return 0;
        } else {
            return 1;
        }
    }
    if (dealer_val >= 17 && dealer_val >= player_val) {
        return 0;
    }
    if (dealer_val < player_val) {
        return 1;
    }
    return 0;
}

void comparacao_final(void) {
    if (resultado_aplicado == 1) {
        return;
    }

    int as_11_1_player;
    int as_11_1_dealer;
    int val_player;
    int val_dealer;
    int total_resultado_player;
    int total_resultado_dealer;

    as_11_1_player = 0;
    as_11_1_dealer = 0;
    val_player = valor_com_as(&player_hand, &as_11_1_player);
    val_dealer = valor_com_as(&dealer_hand, &as_11_1_dealer);
    total_resultado_player = val_player + trinket_bonus_player;
    total_resultado_dealer = val_dealer + trinket_bonus_dealer;

    if (total_resultado_player > 21 && total_resultado_dealer > 21) {
        strcpy(resultado_msg, "Ambos estouraram: Empate");
        last_win = 3;
        fugir_ou_n = 1;

        if (recompensa_aplicada == 0) {
            dinheiro_total = dinheiro_total + 1;
            recompensa_aplicada = 1;
        }
    } else if (total_resultado_player > 21) {
        dealer_ganhou("Estourou: Dealer venceu");
        return;
    } else if (total_resultado_dealer > 21) {
        strcpy(resultado_msg, "Dealer estourou: Voce venceu");
        last_win = 1;

        if (game_over == 0) {
            if (ataque_ativo == 0) {
                if (total_resultado_player == 21) {
                    iniciar_ataque_blackjack();
                } else {
                    iniciar_ataque_normal();
                }
            }
        }

        if (total_resultado_player == 21) {
            if (recompensa_aplicada == 0) {
                dinheiro_total = dinheiro_total + 5;
                recompensa_aplicada = 1;
            }
        } else {
            if (recompensa_aplicada == 0) {
                dinheiro_total = dinheiro_total + 3;
                recompensa_aplicada = 1;
            }
        }

        fugir_ou_n = 1;
    } else if (total_resultado_player > total_resultado_dealer) {
        strcpy(resultado_msg, "Voce venceu");
        last_win = 1;

        if (game_over == 0) {
            if (ataque_ativo == 0) {
                if (total_resultado_player == 21) {
                    iniciar_ataque_blackjack();
                } else {
                    iniciar_ataque_normal();
                }
            }
        }

        if (total_resultado_player == 21) {
            if (recompensa_aplicada == 0) {
                dinheiro_total = dinheiro_total + 5;
                recompensa_aplicada = 1;
            }
        } else {
            if (recompensa_aplicada == 0) {
                dinheiro_total = dinheiro_total + 3;
                recompensa_aplicada = 1;
            }
        }

        fugir_ou_n = 1;
    } else if (total_resultado_player < total_resultado_dealer) {
        dealer_ganhou("Dealer venceu");
        return;
    } else {
        strcpy(resultado_msg, "Empate");
        last_win = 3;
        fugir_ou_n = 1;

        if (recompensa_aplicada == 0) {
            dinheiro_total = dinheiro_total + 1;
            recompensa_aplicada = 1;
        }
    }

    resultado_aplicado = 1;
    espera_menu_fugir = GetTime() + 0.3;
    fugir_ou_n = 1;
    menu_fuga_iniciado = 1;
    opcao_pos_vitoria = 0;
    fugido = 0;
}

void start_battle(void) {
    int player_blackjack;
    int dealer_blackjack;

    trinket_bonus_player = 0;
    trinket_bonus_dealer = 0;

    if (game_over == 1) {
        return;
    }

    resultado_aplicado = 0;
    recompensa_aplicada = 0;
    resultado_msg[0] = '\0';
    last_win = 0;
    ataque_ativo = 0;

    if (fase_atual != NULL) {
        if (fase_atual->vida_max <= 0) {
            fase_atual->vida_max = 1;
        }
        if (fase_atual->vida < 0) {
            fase_atual->vida = 0;
        }
        if (fase_atual->vida > fase_atual->vida_max) {
            fase_atual->vida = fase_atual->vida_max;
        }
    }

    hand_clear(&player_hand);
    hand_clear(&dealer_hand);
    embaralhar();

    puxar_para_mao(&player_hand);
    puxar_para_mao(&dealer_hand);
    puxar_para_mao(&player_hand);
    puxar_para_mao(&dealer_hand);

    player_blackjack = first_hand_blackjack(&player_hand);
    dealer_blackjack = first_hand_blackjack(&dealer_hand);

    if (player_blackjack == 1 && dealer_blackjack == 1) {
        empate("Empate: Blackjacks");
        registrar_resultado_batalha(3);
        return;
    }
    if (player_blackjack == 1 && dealer_blackjack == 0) {
        player_ganhou("Você venceu: Blackjack");

        if (recompensa_aplicada == 0) {
            dinheiro_total = dinheiro_total + 5;
            recompensa_aplicada = 1;
        }

        registrar_resultado_batalha(1);
        return;
    }
    if (player_blackjack == 0 && dealer_blackjack == 1) {
        dealer_ganhou("Dealer venceu: Blackjack");
        registrar_resultado_batalha(0);
        return;
    }

    estado_atual = estado_batalha;
    game_state = estado_player;
}

void player_hitou(void) {
    if (game_state != estado_player) {
        return;
    }

    Carta *carta = puxar_para_mao(&player_hand);

    if (hand_bustou(&player_hand) == 1) {
        dealer_ganhou("Estourou: Dealer venceu");
        return;
    }

    int tem_as_11_1 = 0;
    int total = valor_com_as(&player_hand, &tem_as_11_1);

    if (total == 21) {
        game_state = estado_dealer;
        return;
    }
    return;
}

void player_stand(void) {
    if (game_state != estado_player) {
        return;
    }

    game_state = estado_dealer;
    dealer_prox_acao = GetTime() + delay_do_dealer;
}

void usar_trinket_mais2(void) {
    if (trinket_mais2_count > 0 && game_state == estado_player) {
        trinket_mais2_count--;
        if (inv_count > 0) {
            inv_count--;
        }
        trinket_bonus_player += 2;
    }
}

void usar_trinket_mais4(void) {
    if (trinket_mais4_count > 0 && game_state == estado_player) {
        trinket_mais4_count--;
        if (inv_count > 0) {
            inv_count--;
        }
        trinket_bonus_player += 4;
    }
}

void usar_trinket_menos2(void) {
    if (trinket_menos2_count > 0 && game_state == estado_player) {
        trinket_menos2_count--;
        if (inv_count > 0) {
            inv_count--;
        }
        trinket_bonus_dealer -= 2;
    }
}

void usar_trinket_menos4(void) {
    if (trinket_menos4_count > 0 && game_state == estado_player) {
        trinket_menos4_count--;
        if (inv_count > 0) {
            inv_count--;
        }
        trinket_bonus_dealer -= 4;
    }
}

int dano_do_dealer(int dealer_total) {
    if (dealer_total == 21) {
        return 2;
    }
    return 1;
}
