#include <stdio.h>

#define TAM_TABULEIRO 10  // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3       // tamanho fixo dos navios (3 posições)
#define AGUA 0            // valor que representa água
#define NAVIO 3           // valor que representa parte do navio

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]; // matriz 10x10 representando o tabuleiro

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------------
    // Definição dos navios
    // -------------------------------

    // Navio 1 - horizontal
    int linhaH = 2; // linha inicial
    int colunaH = 4; // coluna inicial

    // Verifica se cabe no tabuleiro (horizontalmente)
    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaH][colunaH + j] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal não cabe no tabuleiro!\n");
        return 1;
    }

    // Navio 2 - vertical
    int linhaV = 5; // linha inicial
    int colunaV = 6; // coluna inicial

    // Verifica se cabe no tabuleiro (verticalmente)
    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {
        // Verifica se não há sobreposição antes de posicionar
        int sobrepoe = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        } else {
            printf("Erro: Navio vertical sobrepõe o navio horizontal!\n");
            return 1;
        }

    } else {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1;
    }

    // -------------------------------
    // Exibe o tabuleiro
    // -------------------------------

    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");

    return 0;
}
