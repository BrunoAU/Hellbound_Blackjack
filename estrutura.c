#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

char *valor_labels[13] = {
    "A",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "J",
    "Q",
    "K"
};

void init_baralho(void) {
    for (int v = 1; v <= 13; v++) {
        todas_cartas[v - 1].valor = v;
        todas_cartas[v - 1].naipe = 0;
        baralho_real[v - 1] = &todas_cartas[v - 1];
    }
    num_cartas = 13;
    topo = 0;
    embaralhar();
}

void embaralhar(void) {
    for (int i = num_cartas - 1; i > 0; i--) {
        int j = GetRandomValue(0, i);
        Carta *temp = baralho_real[i];
        baralho_real[i] = baralho_real[j];
        baralho_real[j] = temp;
    }
    topo = 0;
}

Carta *puxar_carta(void) {
    if (topo >= num_cartas) {
        embaralhar();
    }
    Carta *cart4 = baralho_real[topo];
    topo++;
    return cart4;
}

Carta *puxar_para_mao(Hand *hand) {
    if (hand == NULL) {
        return NULL;
    }
    Carta *cart4 = puxar_carta();
    if (cart4 == NULL) {
        return NULL;
    }
    hand->cartas[hand->quant] = cart4;
    hand->quant++;
    return cart4;
}

void hand_clear(Hand *hand) {
    if (hand == NULL) {
        return;
    }
    hand->quant = 0;
    for (int i = 0; i < 13; i++) {
        hand->cartas[i] = NULL;
    }
}

int valor_carta(Carta *cart4) {
    if (cart4 == NULL) {
        return 0;
    }
    int val = cart4->valor;
    if (val == 1) {
        return 1;
    }
    if (val >= 2 && val <= 10) {
        return val;
    }
    if (val >= 11 && val <= 13) {
        return 10;
    }
    return 0;
}

int valor_com_as(Hand *hand, int *tem_as_11_1) {
    if (hand == NULL) {
        return 0;
    }
    if (tem_as_11_1 != NULL) {
        *tem_as_11_1 = 0;
    }
    int total = 0;
    int quant_as = 0;

    for (int i = 0; i < hand->quant; i++) {
        Carta *cart4 = hand->cartas[i];
        int val = cart4->valor;
        if (val == 1) {
            quant_as++;
            total += 1;
        } else {
            total += valor_carta(cart4);
        }
    }

    if (quant_as > 0) {
        if (total + 10 <= 21) {
            total += 10;
            if (tem_as_11_1 != NULL) {
                *tem_as_11_1 = 1;
            }
        }
    }

    return total;
}
