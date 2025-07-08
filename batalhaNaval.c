#include <stdio.h>

// Desafio Batalha Naval - Nível Novato
// Este programa posiciona dois navios em um tabuleiro 5x5:
// Um navio na vertical e outro na horizontal.

int main() {
    // Cria o tabuleiro 5x5 e inicializa todas as posições com 0 (água)
    int tabuleiro[5][5];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição inicial do navio horizontal
    int linhaH = 2;
    int colunaH = 1;

    // Posição inicial do navio vertical
    int linhaV = 0;
    int colunaV = 4;

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Posiciona o navio horizontalmente (valor 3 representa navio)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Posiciona o navio verticalmente
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Exibe as coordenadas dos navios
    printf("Coordenadas do navio horizontal:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Linha: %d, Coluna: %d\n", linhaH, colunaH + i);
    }

    printf("\nCoordenadas do navio vertical:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("Linha: %d, Coluna: %d\n", linhaV + i, colunaV);
    }

    return 0;
}