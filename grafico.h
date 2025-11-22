#ifndef GRAFICO_H
#define GRAFICO_H

#include "raylib.h"
#include "estrutura.h"

void desenhar_cursor(void);
void desenhar_fundo(void);
void desenhar_baralho(void);
void desenhar_carta(int x, int y, int largura, int altura, Carta *cart4);
void desenhar_hand(Hand *hand, int x, int y, int hidden_first);
void desenhar_bolsa(void);
void desenhar_vida_player(void);
void desenhar_vida_player_hub(void);
void desenhar_vida_dealer(int vida, int vida_max);
int baralho_hitbox(void);
int stand_hitbox(void);
void desenhar_inventario(void);
int abrir_inventario(void);
void criar_hurtbox(void);
void iniciar_ataque_normal(void);
void iniciar_ataque_blackjack(void);
void atualizar_ataque(void);
void desenhar_ataque(void);
void desenhar_vitoria(void);
void desenhar_vitoria21(void);
void desenhar_derrota(void);
void desenhar_continuar(void);
void desenhar_fugir(void);
void desenhar_empate(void);
int hitboxes_fugir_batalha(int *opcao_pos_vitoria);
void desenhar_menu_resultado(void);
int hitboxes_trinkets_inventario(int *trinket_selecionado);
void desenhar_trinkets_inventario(void);
void desenhar_stand(void);
void desenhar_quant_trinkets(void);

#endif
