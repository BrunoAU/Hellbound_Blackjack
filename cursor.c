#include "raylib.h"
#include "cursor.h"
#include "variaveis.h"
#include <stdio.h>

Texture2D cursorPadrao;
Texture2D cursorClicado;
bool clicando = false;
int cursorLoaded = 0;

float escalaCursor = 1.0f;
float ajusteCursorX = 0.45f;
float ajusteCursorY = 0.35f;

void loadCursor(void) {
    if (cursorLoaded == 1) {
        return;
    }

    cursorPadrao = LoadTexture("assets/HAND.png");
    cursorClicado = LoadTexture("assets/CLOSE-HANDS.png");

    if (cursorPadrao.id != 0 && cursorClicado.id != 0) {
        cursorLoaded = 1;
    } else {
        cursorLoaded = 0;
    }
}

void unloadCursor(void) {
    if (cursorPadrao.id != 0) {
        UnloadTexture(cursorPadrao);
    }
    if (cursorClicado.id != 0) {
        UnloadTexture(cursorClicado);
    }

    cursorLoaded = 0;
}

void clickCursor(bool novoEstado) {
    clicando = novoEstado;
}

void desenharCursor(void) {
    Vector2 mouse;
    float mouse_largura;
    float mouse_altura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;
    Texture2D textura;

    if (cursorLoaded == 0) {
        return;
    }

    if (clicando == true) {
        textura = cursorClicado;
    } else {
        textura = cursorPadrao;
    }

    mouse = GetMousePosition();
    mouse_largura = textura.width * escalaCursor;
    mouse_altura = textura.height * escalaCursor;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = textura.width;
    original.height = textura.height;
    destino.x = mouse.x;
    destino.y = mouse.y;
    destino.width = mouse_largura;
    destino.height = mouse_altura;
    origem.x = mouse_largura * ajusteCursorX;
    origem.y = mouse_altura * ajusteCursorY;

    DrawTexturePro(textura, original, destino, origem, 0.0f, WHITE);
}
