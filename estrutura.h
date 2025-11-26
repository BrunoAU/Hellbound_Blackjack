#ifndef ESTRUTURA_H
#define ESTRUTURA_H

typedef struct {
    int valor;
    int naipe;
} Carta;

typedef struct Fase {
    int numero;
    int vida_max;
    int vida;
    struct Fase *next;
} Fase;

typedef struct {
    Carta *cartas[13];
    int quant;
} Hand;

extern int num_cartas;
extern Carta todas_cartas[13];
extern Carta *baralho_real[13];
extern int topo;

void init_baralho(void);
void embaralhar(void);
Carta *puxar_carta(void);
Carta *puxar_para_mao(Hand *hand);
void hand_clear(Hand *hand);

int valor_carta(Carta *cart4);
int valor_com_as(Hand *hand, int *tem_as_11_1);

#endif
