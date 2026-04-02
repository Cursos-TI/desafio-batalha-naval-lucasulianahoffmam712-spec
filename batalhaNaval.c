#include <stdio.h>

int main (){

    printf("TABULEIRO DE BATALHA NAVAL\n");// Imprime o título do jogo.
    printf("  ");// Imprime um espaço para alinhar as letras das colunas.
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0 (água).
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Letras para as colunas.
    for(int j = 0; j < 10; j++){ // Loop para imprimir as letras das colunas.
        printf("%c ", linha[j]);// Imprime as letras de A a J para as colunas.
    }
    for(int i = 1; i < 10; i++){ // Loop para as linhas do tabuleiro.
        printf("\n%d ", i); // Imprime os números de 0 a 9 para as linhas.
        for(int j = 0; j < 10; j++){ // Loop para imprimir o tabuleiro.
            printf("%d ", tabuleiro[i][j]); // Imprime o valor do tabuleiro (0 para água).
        }
    }
    return 0;
}