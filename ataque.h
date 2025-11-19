#ifndef ATAQUE_H
#define ATAQUE_H

#include "raylib.h"

extern int golpe1_ativo;
extern int golpe2_ativo;
extern int golpe3_ativo;
extern int golpe4_ativo;
extern int golpe5_ativo;

void load_golpes(void);
void unload_golpes(void);

void iniciar_golpe(void);
void atualizar_golpe(void);
void desenhar_golpe(void);

#endif
