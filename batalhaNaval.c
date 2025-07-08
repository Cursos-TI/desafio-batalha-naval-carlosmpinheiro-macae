#include <stdio.h>

// Desafio Batalha Naval - Nível Aventureiro
// Posiciona 4 navios em um tabuleiro 10x10, incluindo navios em diagonal.

int main() {
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // Navio 1 – horizontal (linha 1, coluna 2 a 4)
    int linhaH = 1, colunaH = 2;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio 2 – vertical (linha 5 a 7, coluna 0)
    int linhaV = 5, colunaV = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio 3 – diagonal principal (linha 6, coluna 6 → [6][6], [7][7], [8][8])
    int linhaD1 = 6, colunaD1 = 6;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio 4 – diagonal secundária (linha 0, coluna 9 → [0][9], [1][8], [2][7])
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // Exibe o tabuleiro completo
    printf("Tabuleiro 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}