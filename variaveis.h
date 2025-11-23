#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#include "raylib.h"
#include "estrutura.h"

extern Texture2D textura_bolsa;
extern int bolsa_loaded;
extern float escala_bolsa;

extern Texture2D textura_inventario;
extern int inventario_loaded;
extern float inventario_escala;

extern Texture2D textura_coracao_vazio;
extern Texture2D textura_coracao_cheio;
extern int coracao_vazio_loaded;
extern int coracao_cheio_loaded;
extern float escala_coracao;

extern Texture2D textura_baralho;
extern int baralho_loaded;
extern float escala_baralho;

extern Texture2D textura_fundo;
extern int fundo_loaded;

extern Texture2D textura_carta_a;
extern int carta_a_loaded;

extern Texture2D textura_carta_2;
extern int carta_2_loaded;

extern Texture2D textura_carta_3;
extern int carta_3_loaded;

extern Texture2D textura_carta_4;
extern int carta_4_loaded;

extern Texture2D textura_carta_5;
extern int carta_5_loaded;

extern Texture2D textura_carta_6;
extern int carta_6_loaded;

extern Texture2D textura_carta_7;
extern int carta_7_loaded;

extern Texture2D textura_carta_8;
extern int carta_8_loaded;

extern Texture2D textura_carta_9;
extern int carta_9_loaded;

extern Texture2D textura_carta_10;
extern int carta_10_loaded;

extern Texture2D textura_carta_j;
extern int carta_j_loaded;

extern Texture2D textura_carta_q;
extern int carta_q_loaded;

extern Texture2D textura_carta_k;
extern int carta_k_loaded;

extern Texture2D textura_carta_joker;
extern int carta_joker_loaded;

extern int num_cartas;
extern Carta todas_cartas[13];
extern Carta *baralho_real[13];
extern int topo;

extern Hand player_hand;
extern Hand dealer_hand;

extern int estado_atual;
extern int estado_player;
extern int estado_dealer;
extern int estado_resultado;

extern char resultado_msg[256];
extern int last_win;

extern int player_vida_max;
extern int player_vida;
extern int game_over;

extern double dealer_prox_acao;
extern double delay_do_dealer;

extern Fase *fase_head;
extern Fase *fase_atual;

extern int fugir_ou_n;
extern int venceu_todas;
extern double rodada_travada;

extern int ataque_ativo;
extern double ataque_comecou;
extern double ataque_duracao;
extern float ataque_inix;
extern float ataque_iniy;
extern float ataque_fimx;
extern float ataque_fimy;
extern float raio_ataque;
extern float ataque_centro_x;
extern float ataque_centro_y;

extern int inv_open;
extern int inv_max;
extern int inv_count;

extern int estado_parado;
extern int estado_batalha;
extern int estado_mapa;
extern int game_state;

extern int fugir_ou_n;

extern int trinket_mais2_count;
extern int trinket_mais4_count;
extern int trinket_menos2_count;
extern int trinket_menos4_count;

extern int trinket_bonus_player;
extern int trinket_bonus_dealer;

extern int ataque_tipo;
extern int ataque_dano;

extern Rectangle hurtbox_inimigo;
extern int hurtbox_loaded;

extern Texture2D textura_vitoria;
extern int vitoria_loaded;
extern float escala_vitoria;

extern Texture2D textura_derrota;
extern int derrota_loaded;
extern float escala_derrota;

extern int dinheiro_total;
extern int recompensa_aplicada;
extern int resultado_aplicado;

extern Texture2D textura_continuar;
extern int continuar_loaded;
extern float escala_continuar;

extern Texture2D textura_fugir;
extern int fugir_loaded;
extern float escala_fugir;

extern Texture2D textura_stand;
extern int stand_loaded;
extern float escala_stand;

extern Texture2D textura_empate;
extern int empate_loaded;
extern float escala_empate;

extern Texture2D textura_vitoria21;
extern int vitoria21_loaded;
extern float escala_vitoria21;

extern int opcao_pos_vitoria;
extern int menu_fuga_iniciado;
extern int fugido;
extern double espera_menu_fugir;

extern Texture2D textura_trinket_mais4;
extern Texture2D textura_trinket_menos4;
extern Texture2D textura_trinket_mais2;
extern Texture2D textura_trinket_menos2;
extern int trinket_mais4_loaded;
extern int trinket_menos4_loaded;
extern int trinket_mais2_loaded;
extern int trinket_menos2_loaded;

extern int max_dinheiro_gasto_run;
extern int max_dinheiro_gasto_ultima_run;
extern int max_dinheiro_gasto_atual;
extern int max_dinheiro_gasto_salvo;
extern int historico_batalha_salvo;

#endif
