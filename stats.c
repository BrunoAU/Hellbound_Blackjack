#include <stdio.h>
#include "variaveis.h"

void salvar_stats_historico(int max_dinheiro_gasto) {
    FILE *historico;
    historico = fopen("stats_historico.txt", "a");
    if (historico == NULL) {
        return;
    }

    fprintf(historico, "%d\n", max_dinheiro_gasto);
    fclose(historico);
}

int carregar_stats_ultima(int *max_dinheiro_gasto) {
    FILE *historico;
    int valor = 0;
    int achou = 0;
    int scan = 0;

    historico = fopen("stats_historico.txt", "r");
    if (historico == NULL) {
        if (max_dinheiro_gasto != NULL) {
            *max_dinheiro_gasto = 0;
        }
        return 0;
    }
    scan = fscanf(historico, "%d", &valor);

    while (scan == 1) {
        achou = 1;

        if (max_dinheiro_gasto != NULL) {
            *max_dinheiro_gasto = valor;
        }
        scan = fscanf(historico, "%d", &valor);
    }
    fclose(historico);

    if (achou == 0) {
        *max_dinheiro_gasto = 0;
        return 0;
    }
    return 1;
}

void registrar_gasto(int preco) {
    max_dinheiro_gasto_atual = max_dinheiro_gasto_atual + preco;
    if (max_dinheiro_gasto_atual > max_dinheiro_gasto_run) {
        max_dinheiro_gasto_run = max_dinheiro_gasto_atual;
    }
}

void registrar_resultado_batalha(int tipo) {
    int precisa_atualizar;
    precisa_atualizar = 0;

    if (tipo == 0 || tipo == 1 || tipo == 2) {
        precisa_atualizar = 1;
    }
    if (precisa_atualizar == 1) {
        if (max_dinheiro_gasto_run > 0) {
            salvar_stats_historico(max_dinheiro_gasto_run);
        }
    }
}
