#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define H 5 // tamanho das matrizes de habilidade

int main (){

    printf("TABULEIRO DE BATALHA NAVAL\n\n");

    int tabuleiro[TAM][TAM] = {0};

    char linha[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // ================= NAVIOS =================
    int navio[3] = {3,3,3};

    int l1=2,c1=4; // horizontal
    int l2=5,c2=7; // vertical
    int l3=0,c3=0; // diagonal ↘
    int l4=6,c4=2; // diagonal ↙

    // Horizontal
    for(int i=0;i<3;i++)
        if(c1+i < TAM) tabuleiro[l1][c1+i]=3;

    // Vertical
    for(int i=0;i<3;i++)
        if(l2+i < TAM) tabuleiro[l2+i][c2]=3;

    // Diagonal ↘
    for(int i=0;i<3;i++)
        if(l3+i<TAM && c3+i<TAM) tabuleiro[l3+i][c3+i]=3;

    // Diagonal ↙
    for(int i=0;i<3;i++)
        if(l4+i<TAM && c4-i>=0) tabuleiro[l4+i][c4-i]=3;

    // ================= HABILIDADES =================

    int cone[H][H] = {0};
    int cruz[H][H] = {0};
    int octaedro[H][H] = {0};

    int centro = H/2;

    // -------- CONE (aponta para baixo)
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            if(j >= centro - i && j <= centro + i){
                cone[i][j] = 1;
            }
        }
    }

    // -------- CRUZ
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            if(i == centro || j == centro){
                cruz[i][j] = 1;
            }
        }
    }

    // -------- OCTAEDRO (losango)
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            int dist = abs(i - centro) + abs(j - centro);
            if(dist <= centro){
                octaedro[i][j] = 1;
            }
        }
    }

    // ================= POSIÇÕES DAS HABILIDADES =================
    int origemConeL = 2, origemConeC = 2;
    int origemCruzL = 6, origemCruzC = 5;
    int origemOctL  = 4, origemOctC  = 8;

    // ================= SOBREPOSIÇÃO =================

    // Função lógica (inline manual)

    // Cone
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            int l = origemConeL + i - centro;
            int c = origemConeC + j - centro;

            if(l>=0 && l<TAM && c>=0 && c<TAM){
                if(cone[i][j] == 1 && tabuleiro[l][c] == 0){
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }

    // Cruz
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            int l = origemCruzL + i - centro;
            int c = origemCruzC + j - centro;

            if(l>=0 && l<TAM && c>=0 && c<TAM){
                if(cruz[i][j] == 1 && tabuleiro[l][c] == 0){
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }

    // Octaedro
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            int l = origemOctL + i - centro;
            int c = origemOctC + j - centro;

            if(l>=0 && l<TAM && c>=0 && c<TAM){
                if(octaedro[i][j] == 1 && tabuleiro[l][c] == 0){
                    tabuleiro[l][c] = 5;
                }
            }
        }
    }

    // ================= IMPRESSÃO =================

    printf("  ");
    for(int j=0;j<TAM;j++){
        printf("%c ", linha[j]);
    }

    printf("\n");

    for(int i=0;i<TAM;i++){
        printf("%d ", i);

        for(int j=0;j<TAM;j++){

            if(tabuleiro[i][j] == 0)
                printf("0 ");
            else if(tabuleiro[i][j] == 3)
                printf("3 ");
            else if(tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}