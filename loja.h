#ifndef LOJA_H
#define LOJA_H

#include "hub.h"

int inventario_tem_espaco(void);

void comprar_trinket_mais2(void);
void comprar_trinket_menos2(void);
void comprar_trinket_mais4(void);
void comprar_trinket_menos4(void);

void comprar_coracao(Personagem *personagem);
void comprar_itens(Personagem *personagem, int itemID);

void TelaLoja(Personagem *personagem);

#endif
