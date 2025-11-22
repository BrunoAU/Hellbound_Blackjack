#ifndef STATS_H
#define STATS_H

void salvar_stats_historico(int max_dinheiro_gasto);
int carregar_stats_ultima(int *max_dinheiro_gasto);
void registrar_gasto(int preco);
void registrar_resultado_batalha(int tipo);

#endif
