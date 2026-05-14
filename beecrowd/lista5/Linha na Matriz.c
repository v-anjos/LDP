#include <stdio.h>

int main() {
    int L, i, j;
    char T;
    double M[12][12];
    double soma = 0.0;

    scanf("%d", &L);
    scanf(" %c", &T);

    // Leitura da matriz
    for(i = 0; i < 12; i++) {
        for(j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    // Soma dos elementos da linha L
    for(j = 0; j < 12; j++) {
        soma += M[L][j];
    }

    // Saída
    if(T == 'S')
        printf("%.1lf\n", soma);
    else
        printf("%.1lf\n", soma / 12.0);

    return 0;
}
