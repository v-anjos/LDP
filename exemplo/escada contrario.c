#include <stdio.h>

int main() {
    int i, j, w, n;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) { //percorrer as linhas
        for (j = 1; j <= n - i; j++) { //epaços vzios
            printf(" ");
        }
        for (w = 1; w <= i; w++) { //preencher as linha
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
