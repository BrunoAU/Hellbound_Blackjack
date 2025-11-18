#include "raylib.h"
#include "estrutura.h"
#include "variaveis.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

Fase *criar_fases_encadeadas(int total) {
    Fase *head = NULL;
    Fase *atual = NULL;

    for (int i = 1; i <= total; i++) {
        Fase *novo = (Fase *) malloc(sizeof(Fase));
        if (novo == NULL) {
            Fase *fase = head;
            while (fase != NULL) {
                Fase *tmp = fase->next;
                free(fase);
                fase = tmp;
            }
            return NULL;
        }

        novo->numero = i;
        novo->vida_max = i;
        if (novo->vida_max > 10) {
            novo->vida_max = 10;
        }
        if (novo->vida_max < 1) {
            novo->vida_max = 1;
        }
        novo->vida = novo->vida_max;
        novo->next = NULL;

        if (head == NULL) {
            head = novo;
            atual = novo;
        } else {
            atual->next = novo;
            atual = novo;
        }
    }

    return head;
}

void reiniciar_fases(void) {
    Fase *fase = fase_head;

    while (fase != NULL) {
        if (fase->vida_max > 10) {
            fase->vida_max = 10;
        }
        if (fase->vida_max < 1) {
            fase->vida_max = 1;
        }
        fase->vida = fase->vida_max;
        fase = fase->next;
    }

    fase_atual = fase_head;
    prompt_continuar_fase = 0;
    prompt_fugir_ou_n = 0;
    prompt_pos_vitoria = 0;
    venceu_todas = 0;
    auto_nova_rodada = 0;
    auto_ready_time = 0.0;
    rodada_travada = 0.0;
}

void destruir_fases(Fase *head) {
    Fase *fase = head;
    while (fase != NULL) {
        Fase *tmp = fase->next;
        free(fase);
        fase = tmp;
    }
}
