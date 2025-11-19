#ifndef JOGO_H
#define JOGO_H

#include "estrutura.h"

int first_hand_blackjack(Hand *hand);
int hand_bustou(Hand *hand);

void fim_round(char *msg);
void player_ganhou(char *msg);
void empate(char *msg);
void dealer_ganhou(char *msg);

int dealerDevePuxar(int dealer_val, int as_11_1, int player_val);

void comparacao_final(void);
void start_battle(void);
void player_hitou(void);
void player_stand(void);

void usar_trinket_mais2(void);
void usar_trinket_mais4(void);
void usar_trinket_menos2(void);
void usar_trinket_menos4(void);

int dano_do_dealer(int dealer_total);

#endif
