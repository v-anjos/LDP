#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int mat[n][n];
        int i, j;

        // 1. Inicializa a matriz com zeros
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                mat[i][j] = 0;
            }
        }

        // 2. Define as diagonais
        for (i = 0; i < n; i++) {
            mat[i][i] = 2;
            mat[i][n - 1 - i] = 3;
        }

        // 3. Define a parte central interna
        int inicio = n / 3;
        int fim = n - inicio;
        for (i = inicio; i < fim; i++) {
            for (j = inicio; j < fim; j++) {
                mat[i][j] = 1;
            }
        }

        // 4. Define o elemento central exato
        mat[n / 2][n / 2] = 4;

        // 5. Imprime a matriz e a linha em branco obrigatória
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d", mat[i][j]);
            }
            printf("\n"); // Quebra de linha ao fim de cada linha da matriz
        }
        printf("\n"); // Linha em branco exigida após CADA matriz
    }
    return 0;
}
