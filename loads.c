#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include "loads.h"
#include "cursor.h"

Texture2D texturas_final[6];
int final_loaded = 0;

Texture2D textura_game_over_tente;
Texture2D textura_game_over_desisti;
int game_over_loaded = 0;

void load_final(void) {
    if (final_loaded == 1) {
        return;
    }

    texturas_final[0] = LoadTexture("assets/001.png");
    texturas_final[1] = LoadTexture("assets/002.png");
    texturas_final[2] = LoadTexture("assets/003.png");
    texturas_final[3] = LoadTexture("assets/004.png");
    texturas_final[4] = LoadTexture("assets/005.png");
    texturas_final[5] = LoadTexture("assets/006.png");

    if (texturas_final[0].id != 0) {
        final_loaded = 1;
    } else {
        final_loaded = 0;
    }
}

void unload_final(void) {
    if (final_loaded == 1) {
        for (int i = 0; i < 6; i++) {
            if (texturas_final[i].id != 0) {
                UnloadTexture(texturas_final[i]);
            }
        }
    }
    final_loaded = 0;
}

void load_game_over(void) {
    if (game_over_loaded == 1) {
        return;
    }
    textura_game_over_tente = LoadTexture("assets/tentenovamente.png");
    textura_game_over_desisti = LoadTexture("assets/desisti.png");

    if (textura_game_over_tente.id != 0 && textura_game_over_desisti.id != 0) {
        game_over_loaded = 1;
    } else {
        game_over_loaded = 0;
    }
}

void unload_game_over(void) {
    if (game_over_loaded == 1) {
        if (textura_game_over_tente.id != 0) UnloadTexture(textura_game_over_tente);
        if (textura_game_over_desisti.id != 0) UnloadTexture(textura_game_over_desisti);
    }
    game_over_loaded = 0;
}

void load_bolsa(void) {
    if (bolsa_loaded == 1) {
        return;
    }
    textura_bolsa = LoadTexture("resources/bolsa_de_itens.png");
    if (textura_bolsa.id != 0) {
        bolsa_loaded = 1;
    } else {
        bolsa_loaded = 0;
    }
}

void unload_bolsa(void) {
    if (bolsa_loaded == 1 && textura_bolsa.id != 0) {
        UnloadTexture(textura_bolsa);
    }
    bolsa_loaded = 0;
}

void load_inventario(void) {
    if (inventario_loaded == 1) {
        return;
    }
    textura_inventario = LoadTexture("resources/inventario_batalha.png");
    if (textura_inventario.id != 0) {
        inventario_loaded = 1;
    } else {
        inventario_loaded = 0;
    }
}

void unload_inventario(void) {
    if (inventario_loaded == 1 && textura_inventario.id != 0) {
        UnloadTexture(textura_inventario);
    }
    inventario_loaded = 0;
}

void load_coracoes(void) {
    if (coracao_vazio_loaded == 0) {
        textura_coracao_vazio = LoadTexture("resources/Coracao_vazio.png");
        if (textura_coracao_vazio.id != 0) {
            coracao_vazio_loaded = 1;
        } else {
            coracao_vazio_loaded = 0;
        }
    }
    if (coracao_cheio_loaded == 0) {
        textura_coracao_cheio = LoadTexture("resources/Coracao_cheio.png");
        if (textura_coracao_cheio.id != 0) {
            coracao_cheio_loaded = 1;
        } else {
            coracao_cheio_loaded = 0;
        }
    }
}

void unload_coracoes(void) {
    if (coracao_vazio_loaded == 1 && textura_coracao_vazio.id != 0) {
        UnloadTexture(textura_coracao_vazio);
    }
    coracao_vazio_loaded = 0;

    if (coracao_cheio_loaded == 1 && textura_coracao_cheio.id != 0) {
        UnloadTexture(textura_coracao_cheio);
    }
    coracao_cheio_loaded = 0;
}

void load_baralho(void) {
    if (baralho_loaded == 1) {
        return;
    }
    textura_baralho = LoadTexture("resources/Baralho_batalha.png");
    if (textura_baralho.id != 0) {
        baralho_loaded = 1;
    } else {
        baralho_loaded = 0;
    }
}

void unload_baralho(void) {
    if (baralho_loaded == 1 && textura_baralho.id != 0) {
        UnloadTexture(textura_baralho);
    }
    baralho_loaded = 0;
}

void load_fundo(void) {
    if (fundo_loaded == 1) {
        return;
    }
    textura_fundo = LoadTexture("resources/Fundo_Batalha.png");
    if (textura_fundo.id != 0) {
        fundo_loaded = 1;
    } else {
        fundo_loaded = 0;
    }
}

void unload_fundo(void) {
    if (fundo_loaded == 1 && textura_fundo.id != 0) {
        UnloadTexture(textura_fundo);
    }
    fundo_loaded = 0;
}

void load_carta_a(void) {
    if (carta_a_loaded == 1) {
        return;
    }
    textura_carta_a = LoadTexture("resources/cartas_jogo/carta_A.png");
    if (textura_carta_a.id != 0) {
        carta_a_loaded = 1;
    } else {
        carta_a_loaded = 0;
    }
}

void unload_carta_a(void) {
    if (carta_a_loaded == 1 && textura_carta_a.id != 0) {
        UnloadTexture(textura_carta_a);
    }
    carta_a_loaded = 0;
}

void load_carta_2(void) {
    if (carta_2_loaded == 1) {
        return;
    }
    textura_carta_2 = LoadTexture("resources/cartas_jogo/carta_2.png");
    if (textura_carta_2.id != 0) {
        carta_2_loaded = 1;
    } else {
        carta_2_loaded = 0;
    }
}

void unload_carta_2(void) {
    if (carta_2_loaded == 1 && textura_carta_2.id != 0) {
        UnloadTexture(textura_carta_2);
    }
    carta_2_loaded = 0;
}

void load_carta_3(void) {
    if (carta_3_loaded == 1) {
        return;
    }
    textura_carta_3 = LoadTexture("resources/cartas_jogo/carta_3.png");
    if (textura_carta_3.id != 0) {
        carta_3_loaded = 1;
    } else {
        carta_3_loaded = 0;
    }
}

void unload_carta_3(void) {
    if (carta_3_loaded == 1 && textura_carta_3.id != 0) {
        UnloadTexture(textura_carta_3);
    }
    carta_3_loaded = 0;
}

void load_carta_4(void) {
    if (carta_4_loaded == 1) {
        return;
    }
    textura_carta_4 = LoadTexture("resources/cartas_jogo/carta_4.png");
    if (textura_carta_4.id != 0) {
        carta_4_loaded = 1;
    } else {
        carta_4_loaded = 0;
    }
}

void unload_carta_4(void) {
    if (carta_4_loaded == 1 && textura_carta_4.id != 0) {
        UnloadTexture(textura_carta_4);
    }
    carta_4_loaded = 0;
}

void load_carta_5(void) {
    if (carta_5_loaded == 1) {
        return;
    }
    textura_carta_5 = LoadTexture("resources/cartas_jogo/carta_5.png");
    if (textura_carta_5.id != 0) {
        carta_5_loaded = 1;
    } else {
        carta_5_loaded = 0;
    }
}

void unload_carta_5(void) {
    if (carta_5_loaded == 1 && textura_carta_5.id != 0) {
        UnloadTexture(textura_carta_5);
    }
    carta_5_loaded = 0;
}

void load_carta_6(void) {
    if (carta_6_loaded == 1) {
        return;
    }
    textura_carta_6 = LoadTexture("resources/cartas_jogo/carta_6.png");
    if (textura_carta_6.id != 0) {
        carta_6_loaded = 1;
    } else {
        carta_6_loaded = 0;
    }
}

void unload_carta_6(void) {
    if (carta_6_loaded == 1 && textura_carta_6.id != 0) {
        UnloadTexture(textura_carta_6);
    }
    carta_6_loaded = 0;
}

void load_carta_7(void) {
    if (carta_7_loaded == 1) {
        return;
    }
    textura_carta_7 = LoadTexture("resources/cartas_jogo/carta_7.png");
    if (textura_carta_7.id != 0) {
        carta_7_loaded = 1;
    } else {
        carta_7_loaded = 0;
    }
}

void unload_carta_7(void) {
    if (carta_7_loaded == 1 && textura_carta_7.id != 0) {
        UnloadTexture(textura_carta_7);
    }
    carta_7_loaded = 0;
}

void load_carta_8(void) {
    if (carta_8_loaded == 1) {
        return;
    }
    textura_carta_8 = LoadTexture("resources/cartas_jogo/carta_8.png");
    if (textura_carta_8.id != 0) {
        carta_8_loaded = 1;
    } else {
        carta_8_loaded = 0;
    }
}

void unload_carta_8(void) {
    if (carta_8_loaded == 1 && textura_carta_8.id != 0) {
        UnloadTexture(textura_carta_8);
    }
    carta_8_loaded = 0;
}

void load_carta_9(void) {
    if (carta_9_loaded == 1) {
        return;
    }
    textura_carta_9 = LoadTexture("resources/cartas_jogo/carta_9.png");
    if (textura_carta_9.id != 0) {
        carta_9_loaded = 1;
    } else {
        carta_9_loaded = 0;
    }
}

void unload_carta_9(void) {
    if (carta_9_loaded == 1 && textura_carta_9.id != 0) {
        UnloadTexture(textura_carta_9);
    }
    carta_9_loaded = 0;
}

void load_carta_10(void) {
    if (carta_10_loaded == 1) {
        return;
    }
    textura_carta_10 = LoadTexture("resources/cartas_jogo/carta_10.png");
    if (textura_carta_10.id != 0) {
        carta_10_loaded = 1;
    } else {
        carta_10_loaded = 0;
    }
}

void unload_carta_10(void) {
    if (carta_10_loaded == 1 && textura_carta_10.id != 0) {
        UnloadTexture(textura_carta_10);
    }
    carta_10_loaded = 0;
}

void load_carta_j(void) {
    if (carta_j_loaded == 1) {
        return;
    }
    textura_carta_j = LoadTexture("resources/cartas_jogo/carta_J.png");
    if (textura_carta_j.id != 0) {
        carta_j_loaded = 1;
    } else {
        carta_j_loaded = 0;
    }
}

void unload_carta_j(void) {
    if (carta_j_loaded == 1 && textura_carta_j.id != 0) {
        UnloadTexture(textura_carta_j);
    }
    carta_j_loaded = 0;
}

void load_carta_q(void) {
    if (carta_q_loaded == 1) {
        return;
    }
    textura_carta_q = LoadTexture("resources/cartas_jogo/carta_Q.png");
    if (textura_carta_q.id != 0) {
        carta_q_loaded = 1;
    } else {
        carta_q_loaded = 0;
    }
}

void unload_carta_q(void) {
    if (carta_q_loaded == 1 && textura_carta_q.id != 0) {
        UnloadTexture(textura_carta_q);
    }
    carta_q_loaded = 0;
}

void load_carta_k(void) {
    if (carta_k_loaded == 1) {
        return;
    }
    textura_carta_k = LoadTexture("resources/cartas_jogo/carta_K.png");
    if (textura_carta_k.id != 0) {
        carta_k_loaded = 1;
    } else {
        carta_k_loaded = 0;
    }
}

void unload_carta_k(void) {
    if (carta_k_loaded == 1 && textura_carta_k.id != 0) {
        UnloadTexture(textura_carta_k);
    }
    carta_k_loaded = 0;
}

void load_carta_joker(void) {
    if (carta_joker_loaded == 1) {
        return;
    }
    textura_carta_joker = LoadTexture("resources/cartas_jogo/carta_joker.png");
    if (textura_carta_joker.id != 0) {
        carta_joker_loaded = 1;
    } else {
        carta_joker_loaded = 0;
    }
}

void unload_carta_joker(void) {
    if (carta_joker_loaded == 1 && textura_carta_joker.id != 0) {
        UnloadTexture(textura_carta_joker);
    }
    carta_joker_loaded = 0;
}

void load_vitoria(void) {
    if (vitoria_loaded == 1) {
        return;
    }
    textura_vitoria = LoadTexture("resources/voce_venceu.png");
    if (textura_vitoria.id != 0) {
        vitoria_loaded = 1;
    } else {
        vitoria_loaded = 0;
    }
}

void unload_vitoria(void) {
    if (vitoria_loaded == 1 && textura_vitoria.id != 0) {
        UnloadTexture(textura_vitoria);
    }
    vitoria_loaded = 0;
}

void load_vitoria21(void) {
    if (vitoria21_loaded == 1) {
        return;
    }
    textura_vitoria21 = LoadTexture("resources/voce_venceu21.png");
    if (textura_vitoria21.id != 0) {
        vitoria21_loaded = 1;
    } else {
        vitoria21_loaded = 0;
    }
}

void unload_vitoria21(void) {
    if (vitoria21_loaded == 1 && textura_vitoria21.id != 0) {
        UnloadTexture(textura_vitoria21);
    }
    vitoria21_loaded = 0;
}

void load_derrota(void) {
    if (derrota_loaded == 1) {
        return;
    }
    textura_derrota = LoadTexture("resources/voce_perdeu.png");
    if (textura_derrota.id != 0) {
        derrota_loaded = 1;
    } else {
        derrota_loaded = 0;
    }
}

void unload_derrota(void) {
    if (derrota_loaded == 1 && textura_derrota.id != 0) {
        UnloadTexture(textura_derrota);
    }
    derrota_loaded = 0;
}

void load_stand(void) {
    if (stand_loaded == 1) {
        return;
    }

    textura_stand = LoadTexture("resources/STAND.png");
    if (textura_stand.id != 0) {
        stand_loaded = 1;
    } else {
        stand_loaded = 0;
    }
}

void unload_stand(void) {
    if (stand_loaded == 1 && textura_stand.id != 0) {
        UnloadTexture(textura_stand);
    }
    stand_loaded = 0;
}

void load_empate(void) {
    if (empate_loaded == 1) {
        return;
    }
    textura_empate = LoadTexture("resources/empate.png");
    if (textura_empate.id != 0) {
        empate_loaded = 1;
    } else {
        empate_loaded = 0;
    }
}

void unload_empate(void) {
    if (empate_loaded == 1 && textura_empate.id != 0) {
        UnloadTexture(textura_empate);
    }
    empate_loaded = 0;
}

void load_fugir(void) {
    if (fugir_loaded == 1) {
        return;
    }

    textura_fugir = LoadTexture("resources/sair_batalha.png");
    if (textura_fugir.id != 0) {
        fugir_loaded = 1;
    } else {
        fugir_loaded = 0;
    }
}

void unload_fugir(void) {
    if (fugir_loaded == 1 && textura_fugir.id != 0) {
        UnloadTexture(textura_fugir);
    }
    fugir_loaded = 0;
}

void load_continuar(void) {
    if (continuar_loaded == 1) {
        return;
    }

    textura_continuar = LoadTexture("resources/continuar_batalha.png");
    if (textura_continuar.id != 0) {
        continuar_loaded = 1;
    } else {
        continuar_loaded = 0;
    }
}

void unload_continuar(void) {
    if (continuar_loaded == 1 && textura_continuar.id != 0) {
        UnloadTexture(textura_continuar);
    }
    continuar_loaded = 0;
}

void load_trinket_mais4(void) {
    if (trinket_mais4_loaded == 1) {
        return;
    }

    textura_trinket_mais4 = LoadTexture("resources/sprite_mais4.png");
    if (textura_trinket_mais4.id != 0) {
        trinket_mais4_loaded = 1;
    } else {
        trinket_mais4_loaded = 0;
    }
}

void unload_trinket_mais4(void) {
    if (trinket_mais4_loaded == 1 && textura_trinket_mais4.id != 0) {
        UnloadTexture(textura_trinket_mais4);
    }
    trinket_mais4_loaded = 0;
}

void load_trinket_menos4(void) {
    if (trinket_menos4_loaded == 1) {
        return;
    }

    textura_trinket_menos4 = LoadTexture("resources/sprite_menos4.png");
    if (textura_trinket_menos4.id != 0) {
        trinket_menos4_loaded = 1;
    } else {
        trinket_menos4_loaded = 0;
    }
}

void unload_trinket_menos4(void) {
    if (trinket_menos4_loaded == 1 && textura_trinket_menos4.id != 0) {
        UnloadTexture(textura_trinket_menos4);
    }
    trinket_menos4_loaded = 0;
}

void load_trinket_mais2(void) {
    if (trinket_mais2_loaded == 1) {
        return;
    }

    textura_trinket_mais2 = LoadTexture("resources/sprite_mais2.png");
    if (textura_trinket_mais2.id != 0) {
        trinket_mais2_loaded = 1;
    } else {
        trinket_mais2_loaded = 0;
    }
}

void unload_trinket_mais2(void) {
    if (trinket_mais2_loaded == 1 && textura_trinket_mais2.id != 0) {
        UnloadTexture(textura_trinket_mais2);
    }
    trinket_mais2_loaded = 0;
}

void load_trinket_menos2(void) {
    if (trinket_menos2_loaded == 1) {
        return;
    }

    textura_trinket_menos2 = LoadTexture("resources/sprite_menos2.png");
    if (textura_trinket_menos2.id != 0) {
        trinket_menos2_loaded = 1;
    } else {
        trinket_menos2_loaded = 0;
    }
}

void unload_trinket_menos2(void) {
    if (trinket_menos2_loaded == 1 && textura_trinket_menos2.id != 0) {
        UnloadTexture(textura_trinket_menos2);
    }
    trinket_menos2_loaded = 0;
}

void load_trinkets_inventario(void) {
    load_trinket_mais4();
    load_trinket_menos4();
    load_trinket_mais2();
    load_trinket_menos2();
}

void unload_trinkets_inventario(void) {
    unload_trinket_mais4();
    unload_trinket_menos4();
    unload_trinket_mais2();
    unload_trinket_menos2();
}

void load_todas_cartas(void) {
    load_carta_a();
    load_carta_2();
    load_carta_3();
    load_carta_4();
    load_carta_5();
    load_carta_6();
    load_carta_7();
    load_carta_8();
    load_carta_9();
    load_carta_10();
    load_carta_j();
    load_carta_q();
    load_carta_k();
    load_carta_joker();
}

void unload_todas_cartas(void) {
    unload_carta_a();
    unload_carta_2();
    unload_carta_3();
    unload_carta_4();
    unload_carta_5();
    unload_carta_6();
    unload_carta_7();
    unload_carta_8();
    unload_carta_9();
    unload_carta_10();
    unload_carta_j();
    unload_carta_q();
    unload_carta_k();
    unload_carta_joker();
}

void load_tudo(void) {
    loadCursor();
    load_bolsa();
    load_inventario();
    load_coracoes();
    load_baralho();
    load_fundo();
    load_vitoria();
    load_vitoria21();
    load_derrota();
    load_continuar();
    load_fugir();
    load_stand();
    load_empate();
    load_trinkets_inventario();
    load_final();
    load_game_over();
    load_todas_cartas();
}

void unload_tudo(void) {
    unloadCursor();
    unload_bolsa();
    unload_inventario();
    unload_coracoes();
    unload_baralho();
    unload_fundo();
    unload_vitoria();
    unload_vitoria21();
    unload_derrota();
    unload_continuar();
    unload_fugir();
    unload_stand();
    unload_empate();
    unload_trinkets_inventario();
    unload_final();
    unload_game_over();
    unload_todas_cartas();
}
