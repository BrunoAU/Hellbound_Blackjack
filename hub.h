#ifndef HUB_H
#define HUB_H

typedef struct {
    char *nome;
    int coracoes;
    int coracoes_max;
    int dinheiro;
} Personagem;

void TelaHub(Personagem personagem);

#endif
