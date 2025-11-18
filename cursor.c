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
    float mouseLargura;
    float mouseAltura;
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
    mouseLargura = (float)textura.width * escalaCursor;
    mouseAltura = (float)textura.height * escalaCursor;

    original = (Rectangle){0.0f, 0.0f, (float)textura.width, (float)textura.height};
    destino = (Rectangle){mouse.x, mouse.y, mouseLargura, mouseAltura};
    origem = (Vector2){mouseLargura * ajusteCursorX, mouseAltura * ajusteCursorY};

    DrawTexturePro(textura, original, destino, origem, 0.0f, WHITE);
}
