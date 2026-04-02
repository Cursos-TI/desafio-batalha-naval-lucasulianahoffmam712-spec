#include <stdio.h>

int main (){

    printf("TABULEIRO DE BATALHA NAVAL\n");

    // Matriz do tabuleiro (10x10), inicializada com 0 (água)
    int tabuleiro[10][10] = {0};

    // Letras para identificar colunas
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // DEFINIÇÃO DOS NAVIOS
  

    int navio1[3] = {3, 3, 3}; // Navio horizontal
    int navio2[3] = {3, 3, 3}; // Navio vertical

    // Coordenadas iniciais
    int linha_navio1 = 2, coluna_navio1 = 4; // Horizontal
    int linha_navio2 = 5, coluna_navio2 = 7; // Vertical


    // VALIDAÇÃO E POSICIONAMENTO

    // NAVIO 1 (HORIZONTAL)
    if (coluna_navio1 + 3 <= 10) { // Verifica se cabe no tabuleiro
        int sobreposicao = 0;

        // Verifica sobreposição
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = navio1[i];
            }
        }
    }

    //NAVIO 2 (VERTICAL)
    if (linha_navio2 + 3 <= 10) { // Verifica se cabe no tabuleiro
        int sobreposicao = 0;

        // Verifica sobreposição
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                sobreposicao = 1;
            }
        }

        // Posiciona se não houver sobreposição
        if (!sobreposicao) {
            for (int i = 0; i < 3; i++) {
                tabuleiro[linha_navio2 + i][coluna_navio2] = navio2[i];
            }
        }
    }

    printf("  ");
    for(int j = 0; j < 10; j++){
        printf("%c ", linha[j]); // Cabeçalho (A-J)
    }

    // Loop das linhas
    for(int i = 0; i < 10; i++){
        printf("\n%d ", i); // Número da linha

        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]); // 0 = água, 3 = navio
        }
    }

    printf("\n");

    return 0;
}