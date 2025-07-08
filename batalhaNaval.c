#include <stdio.h>

// Desafio Batalha Naval - Nível Mestre
// Aplicação de habilidades especiais: Cone, Cruz e Octaedro

#define TAMANHO 10 // Tamanho do tabuleiro

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro com habilidades especiais:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origemLinha - 2 + i;
            int coluna = origemColuna - 2 + j;

            // Condicional para evitar posições fora do tabuleiro
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha][coluna] = 5; // Marca área afetada com 5
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com 0
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Matriz Cone (5x5)
    int cone[5][5];
    for (int i = 0; i < 5; i++) {          // Linha
        for (int j = 0; j < 5; j++) {      // Coluna
            if (j >= 2 - i && j <= 2 + i)  // Expande horizontalmente conforme a linha
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Matriz Cruz (5x5)
    int cruz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Matriz Octaedro (5x5)
    int octaedro[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Aplica as habilidades em pontos específicos
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone com origem em [2][2]
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz com origem em [5][5]
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);   // Octaedro com origem em [7][8]

    // Exibe o tabuleiro final com áreas afetadas
    exibirTabuleiro(tabuleiro);

    return 0;
}