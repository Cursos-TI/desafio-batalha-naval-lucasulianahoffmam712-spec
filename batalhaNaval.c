#include <stdio.h>

int main (){

    printf("TABULEIRO DE BATALHA NAVAL\n");

    // Matriz do tabuleiro (10x10), inicializada com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para identificar colunas
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // DEFINIÇÃO DOS NAVIOS
    int navio1[3] = {3, 3, 3}; // Horizontal
    int navio2[3] = {3, 3, 3}; // Vertical
    int navio3[3] = {3, 3, 3}; // Diagonal ↘
    int navio4[3] = {3, 3, 3}; // Diagonal ↙

    // Coordenadas iniciais
    int linha_navio1 = 2, coluna_navio1 = 4; // Horizontal
    int linha_navio2 = 5, coluna_navio2 = 7; // Vertical
    int linha_navio3 = 0, coluna_navio3 = 0; // Diagonal ↘
    int linha_navio4 = 6, coluna_navio4 = 2; // Diagonal ↙

    // -------------------------------
    // NAVIO 1 (HORIZONTAL)
    if (coluna_navio1 + 3 <= 10) {
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = navio1[i];
            }
        }
    }

    // -------------------------------
    // NAVIO 2 (VERTICAL)
    if (linha_navio2 + 3 <= 10) {
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio2 + i][coluna_navio2] = navio2[i];
            }
        }
    }

    // -------------------------------
    // NAVIO 3 (DIAGONAL ↘)
    if (linha_navio3 + 3 <= 10 && coluna_navio3 + 3 <= 10) {
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio3 + i][coluna_navio3 + i] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio3 + i][coluna_navio3 + i] = navio3[i];
            }
        }
    }

    // -------------------------------
    // NAVIO 4 (DIAGONAL ↙)
    if (linha_navio4 + 3 <= 10 && coluna_navio4 - 2 >= 0) {
        int sobreposicao = 0;

        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio4 + i][coluna_navio4 - i] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio4 + i][coluna_navio4 - i] = navio4[i];
            }
        }
    }

    // -------------------------------
    // IMPRESSÃO DO TABULEIRO

    printf("  ");
    for(int j = 0; j < 10; j++){
        printf("%c ", linha[j]);
    }

    for(int i = 0; i < 10; i++){
        printf("\n%d ", i);

        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
    }

    printf("\n");

    return 0;
}