#ifndef CURSOR_H
#define CURSOR_H

#include "raylib.h"
#include <stdbool.h>

extern Texture2D cursorPadrao;
extern Texture2D cursorClicado;
extern bool clicando;
extern int cursorLoaded;

extern float escalaCursor;
extern float ajusteCursorX;
extern float ajusteCursorY;

void loadCursor(void);
void unloadCursor(void);
void clickCursor(bool novoEstado);
void desenharCursor(void);

#endif
