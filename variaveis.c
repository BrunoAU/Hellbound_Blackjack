#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"

Texture2D textura_bolsa;
int bolsa_loaded = 0;
float escala_bolsa = 1.0f;

Texture2D textura_coracao_vazio;
Texture2D textura_coracao_cheio;
int coracao_vazio_loaded = 0;
int coracao_cheio_loaded = 0;
float escala_coracao = 0.35f;

Texture2D textura_baralho;
int baralho_loaded = 0;
float escala_baralho = 0.70f;

Texture2D textura_fundo;
int fundo_loaded = 0;

Texture2D textura_carta_a;
int carta_a_loaded = 0;

Texture2D textura_carta_2;
int carta_2_loaded = 0;

Texture2D textura_carta_3;
int carta_3_loaded = 0;

Texture2D textura_carta_4;
int carta_4_loaded = 0;

Texture2D textura_carta_5;
int carta_5_loaded = 0;

Texture2D textura_carta_6;
int carta_6_loaded = 0;

Texture2D textura_carta_7;
int carta_7_loaded = 0;

Texture2D textura_carta_8;
int carta_8_loaded = 0;

Texture2D textura_carta_9;
int carta_9_loaded = 0;

Texture2D textura_carta_10;
int carta_10_loaded = 0;

Texture2D textura_carta_j;
int carta_j_loaded = 0;

Texture2D textura_carta_q;
int carta_q_loaded = 0;

Texture2D textura_carta_k;
int carta_k_loaded = 0;

Texture2D textura_carta_joker;
int carta_joker_loaded = 0;

int num_cartas = 13;
Carta todas_cartas[13];
Carta *baralho_real[13];
int topo = 0;

Hand player_hand;
Hand dealer_hand;

char resultado_msg[256];
int last_win = 0;

int player_vida_max = 5;
int player_vida = 0;
int game_over = 0;

double dealer_prox_acao = 0.0;
double delay_do_dealer = 0.90;

Fase *fase_head = 0;
Fase *fase_atual = 0;

int venceu_todas = 0;
double rodada_travada = 0.0;

int ataque_ativo = 0;
double ataque_comecou = 0.0;
double ataque_duracao = 0.60;
float ataque_inix = 0.0f;
float ataque_iniy = 0.0f;
float ataque_fimx = 0.0f;
float ataque_fimy = 0.0f;
float raio_ataque = 0.0f;
float ataque_centro_x = 0.0f;
float ataque_centro_y = 0.0f;

int inv_open = 0;
int inv_max = 3;
int inv_count = 0;

Texture2D textura_inventario;
int inventario_loaded = 0;
float inventario_escala = 0.5f;

int game_state = 0;
int estado_parado = 0;
int estado_player = 1;
int estado_dealer = 2;
int estado_resultado = 3;
int estado_atual = 0;
int estado_batalha = 1;
int estado_mapa = 2;

int fugir_ou_n = 0;

int trinket_mais2_count = 0;
int trinket_mais4_count = 0;
int trinket_menos2_count = 0;
int trinket_menos4_count = 0;

int trinket_bonus_player = 0;
int trinket_bonus_dealer = 0;

Rectangle hurtbox_inimigo = {0};
int hurtbox_loaded = 0;

int ataque_tipo = 0;
int ataque_dano = 1;

Texture2D textura_vitoria;
int vitoria_loaded = 0;
float escala_vitoria = 0.5f;

int dinheiro_total = 0;
int recompensa_aplicada = 0;
int resultado_aplicado = 0;

Texture2D textura_derrota;
int derrota_loaded = 0;
float escala_derrota = 0.5f;

Texture2D textura_continuar;
int continuar_loaded = 0;
float escala_continuar = 0.5f;

Texture2D textura_empate;
int empate_loaded = 0;
float escala_empate = 0.5f;

Texture2D textura_fugir;
int fugir_loaded = 0;
float escala_fugir = 0.5f;

Texture2D textura_stand;
int stand_loaded = 0;
float escala_stand = 1.0f;

Texture2D textura_vitoria21;
int vitoria21_loaded = 0;
float escala_vitoria21 = 0.5f;

int opcao_pos_vitoria = 0;
int menu_fuga_iniciado = 0;
int fugido = 0;
double espera_menu_fugir = 0.0;

Texture2D textura_trinket_mais4;
int trinket_mais4_loaded = 0;
Texture2D textura_trinket_menos4;
int trinket_menos4_loaded = 0;
Texture2D textura_trinket_mais2;
int trinket_mais2_loaded = 0;
Texture2D textura_trinket_menos2;
int trinket_menos2_loaded = 0;

int max_dinheiro_gasto_run = 0;
int max_dinheiro_gasto_ultima_run = 0;
int max_dinheiro_gasto_atual = 0;
int max_dinheiro_gasto_salvo = 0;
int historico_batalha_salvo = 0;
