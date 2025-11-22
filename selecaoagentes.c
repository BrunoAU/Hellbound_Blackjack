#include "raylib.h"
#include <stdio.h>
#include "hub.h"
#include "variaveis.h"
#include "selecaoagentes.h"
#include "tutorial.h" 

int guerreiro = 0;
int maga = 1;
int arqueiro = 2;
int parado = 0;
int animado = 1;
int frames = 8;
float frameRate = 12.0f;

typedef struct{
    Texture2D frames[8];
} AnimacaoPersonagem;

void CarregarAnimacoes(AnimacaoPersonagem *guerreiro, AnimacaoPersonagem *maga, AnimacaoPersonagem *arqueiro) {
    char *guerreiro_frames[8] = {
        "assets/Frame_1_guerreiro.png",
        "assets/Frame_2_guerreiro.png",
        "assets/Frame_3_guerreiro.png",
        "assets/Frame_4_guerreiro.png",
        "assets/Frame_5_guerreiro.png",
        "assets/Frame_6_guerreiro.png",
        "assets/Frame_7_guerreiro.png",
        "assets/Frame_final_guerreiro.png"
    };
    char *maga_frames[8] = {
        "assets/Frame_1_maga.png",
        "assets/Frame_2_maga.png",
        "assets/Frame_3_maga.png",
        "assets/Frame_4_maga.png",
        "assets/Frame_5_maga.png",
        "assets/Frame_6_maga.png",
        "assets/Frame_7_maga.png",
        "assets/Frame_final_maga.png"
    };
    char *arqueiro_frames[8] = {
        "assets/Frame_1_arqueiro.png",
        "assets/Frame_2_arqueiro.png",
        "assets/Frame_3_arqueiro.png",
        "assets/Frame_4_arqueiro.png",
        "assets/Frame_5_arqueiro.png",
        "assets/Frame_6_arqueiro.png",
        "assets/Frame_7_arqueiro.png",
        "assets/Frame_final_arqueiro.png"
    };

    for (int i = 0; i < frames; i++) {
        guerreiro->frames[i] = LoadTexture(guerreiro_frames[i]);
        maga->frames[i] = LoadTexture(maga_frames[i]);
        arqueiro->frames[i] = LoadTexture(arqueiro_frames[i]);
    }
}

void AtualizarSelecao(int *estado, int *personagemSel, int *personagemConfirmado, bool *jogoIniciado) {
    bool mudou;
    mudou = false;

    if (IsKeyPressed(KEY_RIGHT) == 1 || IsKeyPressed(KEY_D) == 1) {
        (*personagemSel)++;
        if (*personagemSel > arqueiro) {
            *personagemSel = guerreiro;
        }
        mudou = true;
    }
    if (IsKeyPressed(KEY_LEFT) == 1 || IsKeyPressed(KEY_A) == 1) {
        (*personagemSel)--;
        if (*personagemSel < guerreiro) {
            *personagemSel = arqueiro;
        }
        mudou = true;
    }

    if (mudou == true) {
        *estado = animado;
    }
    if (IsKeyPressed(KEY_ENTER) == 1) {
        *personagemConfirmado = *personagemSel;
        *jogoIniciado = true;
    }
}

void AtualizarAnimacao(int* estado, int* frameAtual, float* timer){
    *timer += GetFrameTime();
    if(*timer >= (1.0f/frameRate)){
        *timer = 0.0f;
        (*frameAtual)++;
        if(*frameAtual >= frames){
            *frameAtual = 0;
            *estado = parado;
        }
    }
}

void DesenharSelecao(Texture2D fundo, int estado, int personagemSel, 
    AnimacaoPersonagem guerreiro, AnimacaoPersonagem maga, AnimacaoPersonagem arqueiro, int frameAtual){
    Texture2D frame_desenhar;
    Rectangle destino;
    Rectangle original_fundo;
    Rectangle original_frame;
    Vector2 origem;

    if (estado == parado) {
        if (personagemSel == 0) {
            frame_desenhar = guerreiro.frames[7];
        } else if (personagemSel == 1) {
            frame_desenhar = maga.frames[7];
        } else if (personagemSel == 2) {
            frame_desenhar = arqueiro.frames[7];
        }
    } else {
        if (personagemSel == 0) {
            frame_desenhar = guerreiro.frames[frameAtual];
        } else if (personagemSel == 1) {
            frame_desenhar = maga.frames[frameAtual];
        } else if (personagemSel == 2) {
            frame_desenhar = arqueiro.frames[frameAtual];
        }
    }
    
    destino.x = 0.0f;
    destino.y = 0.0f;
    destino.width = GetScreenWidth();
    destino.height = GetScreenHeight();
    
    original_fundo.x = 0.0f;
    original_fundo.y = 0.0f;
    original_fundo.width = fundo.width;
    original_fundo.height = fundo.height;

    original_frame.x = 0.0f;
    original_frame.y = 0.0f;
    original_frame.width = frame_desenhar.width;
    original_frame.height = frame_desenhar.height;
    origem.x = 0.0f;
    origem.y = 0.0f;

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(fundo, original_fundo, destino, origem, 0.0f, WHITE);
    DrawTexturePro(frame_desenhar, original_frame, destino, origem, 0.0f, WHITE);
    EndDrawing();
}

void FinalizarSelecao(Texture2D fundo, AnimacaoPersonagem guerreiro, AnimacaoPersonagem maga, AnimacaoPersonagem arqueiro){
    UnloadTexture(fundo);
    for(int i=0;i<frames;i++){
        UnloadTexture(guerreiro.frames[i]);
        UnloadTexture(maga.frames[i]);
        UnloadTexture(arqueiro.frames[i]);
    }
}

void MostrarProximaTela(int personagemConfirmado) {
    Personagem p;
    p.dinheiro = 0; 

    if(personagemConfirmado == 0){
        p.nome = "Guerreiro";
        p.coracoes = 5;
        p.coracoes_max = 5; 
    }else if(personagemConfirmado == 1){
        p.nome = "Maga";
        p.coracoes = 3;
        p.coracoes_max = 3;
    }else{
        p.nome = "Arqueiro";
        p.coracoes = 4;
        p.coracoes_max = 4; 
    }
    player_vida_max = p.coracoes_max;
    player_vida = p.coracoes;
    
    RodarTelaTutorial(p); 
}

int RodarTelaSelecao(void){
    Texture2D fundo = LoadTexture("assets/Fundo.png");
    AnimacaoPersonagem animGuerreiro, animMaga, animArqueiro;
    CarregarAnimacoes(&animGuerreiro, &animMaga, &animArqueiro);

    int estado = parado;
    int personagemSel = guerreiro;
    int frameAnimAtual = 0;
    float timerAnim = 0.0f;
    bool jogoIniciado = false;
    int personagemConfirmado = guerreiro;

    while (IsKeyDown(KEY_ENTER)) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("CARREGANDO...", 10, 10, 20, GRAY);
        EndDrawing();
    }

    while(WindowShouldClose() == 0 && jogoIniciado == 0){ 
        AtualizarSelecao(&estado, &personagemSel, &personagemConfirmado, &jogoIniciado);

        if (estado == animado) {
            AtualizarAnimacao(&estado, &frameAnimAtual, &timerAnim);
        }

        DesenharSelecao(fundo, estado, personagemSel, animGuerreiro, animMaga, animArqueiro, frameAnimAtual);
    }
    FinalizarSelecao(fundo, animGuerreiro, animMaga, animArqueiro);
    
    if(jogoIniciado == 1){
        MostrarProximaTela(personagemConfirmado);
    }
    return 0;
}
