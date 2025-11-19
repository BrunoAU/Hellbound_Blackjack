#include "raylib.h"
#include "ataque.h"
#include <stdio.h>

Texture2D golpe1_textura;
Texture2D golpe2_textura;
Texture2D golpe3_textura;
Texture2D golpe4_textura;
Texture2D golpe5_textura;

int golpes_loaded = 0;
int golpe_ativo = 0;
int golpe_frame = 0;
double golpe_proximo_tempo = 0.0;
double golpe_intervalo = 0.18;
float golpe_escala = 1.0f;

int golpe1_ativo = 0;
int golpe2_ativo = 0;
int golpe3_ativo = 0;
int golpe4_ativo = 0;
int golpe5_ativo = 0;

void load_golpes(void) {
    golpe1_textura = LoadTexture("resources/golpe_1.png");
    golpe2_textura = LoadTexture("resources/golpe_2.png");
    golpe3_textura = LoadTexture("resources/golpe_3.png");
    golpe4_textura = LoadTexture("resources/golpe_4.png");
    golpe5_textura = LoadTexture("resources/golpe_5.png");

    if (golpe1_textura.id == 0 || golpe2_textura.id == 0 || golpe3_textura.id == 0 || golpe4_textura.id == 0 || golpe5_textura.id == 0) {

        if (golpe1_textura.id != 0) {
            UnloadTexture(golpe1_textura);
        }
        if (golpe2_textura.id != 0) {
            UnloadTexture(golpe2_textura);
        }
        if (golpe3_textura.id != 0) {
            UnloadTexture(golpe3_textura);
        }
        if (golpe4_textura.id != 0) {
            UnloadTexture(golpe4_textura);
        }
        if (golpe5_textura.id != 0) {
            UnloadTexture(golpe5_textura);
        }

        golpes_loaded = 0;
        return;
    }

    golpes_loaded = 1;
}

void unload_golpes(void) {
    if (golpes_loaded == 0) {
        return;
    }

    if (golpe1_textura.id != 0) {
        UnloadTexture(golpe1_textura);
    }
    if (golpe2_textura.id != 0) {
        UnloadTexture(golpe2_textura);
    }
    if (golpe3_textura.id != 0) {
        UnloadTexture(golpe3_textura);
    }
    if (golpe4_textura.id != 0) {
        UnloadTexture(golpe4_textura);
    }
    if (golpe5_textura.id != 0) {
        UnloadTexture(golpe5_textura);
    }

    golpes_loaded = 0;
}

void atualizar_estado_golpes(void) {
    golpe1_ativo = 0;
    golpe2_ativo = 0;
    golpe3_ativo = 0;
    golpe4_ativo = 0;
    golpe5_ativo = 0;

    if (golpe_frame == 1) {
        golpe1_ativo = 1;
    } else if (golpe_frame == 2) {
        golpe2_ativo = 1;
    } else if (golpe_frame == 3) {
        golpe3_ativo = 1;
    } else if (golpe_frame == 4) {
        golpe4_ativo = 1;
    } else if (golpe_frame == 5) {
        golpe5_ativo = 1;
    }
}

void iniciar_golpe(void) {
    if (golpes_loaded == 0) {
        load_golpes();
    }

    golpe_ativo = 1;
    golpe_frame = 1;
    golpe_proximo_tempo = GetTime() + golpe_intervalo;

    atualizar_estado_golpes();
}

void atualizar_golpe(void) {
    double agora;

    if (golpe_ativo == 0) {
        return;
    }
    agora = GetTime();

    if (agora < golpe_proximo_tempo) {
        return;
    }
    golpe_frame++;

    if (golpe_frame > 5) {
        golpe_ativo = 0;
        golpe_frame = 0;
        atualizar_estado_golpes();
        return;
    }

    golpe_proximo_tempo = agora + golpe_intervalo;
    atualizar_estado_golpes();
}

void desenhar_golpe(void) {
    Texture2D *golpe_textura;
    Rectangle original;
    Rectangle destino;
    Vector2 origem;
    float largura;
    float altura;
    float x;
    float y;

    if (golpe_ativo == 0) {
        return;
    }
  
    x = 1250.0f;
    y = 65.0f;

    golpe_textura = 0;
    if (golpe_frame == 1) {
        golpe_textura = &golpe1_textura;
    } else if (golpe_frame == 2) {
        golpe_textura = &golpe2_textura;
    } else if (golpe_frame == 3) {
        golpe_textura = &golpe3_textura;
    } else if (golpe_frame == 4) {
        golpe_textura = &golpe4_textura;
    } else if (golpe_frame == 5) {
        golpe_textura = &golpe5_textura;
    }

    if (golpe_textura == 0) {
        return;
    }
    if (golpe_textura->id == 0) {
        return;
    }

    largura = golpe_textura->width * golpe_escala;
    altura = golpe_textura->height * golpe_escala;

    original.x = 0.0f;
    original.y = 0.0f;
    original.width = golpe_textura->width;
    original.height = golpe_textura->height;
    destino.x = x;
    destino.y = y;
    destino.width = largura;
    destino.height = altura;
    origem.x = 0.0f;
    origem.y = 0.0f;

    DrawTexturePro(*golpe_textura, original, destino, origem, 0.0f, WHITE);
}
