#include <stdio.h>

int main() {
    int tamanho = 5, i, j;
    for ( i = 0; i < tamanho; i++) { 
        for ( j = 0; j < tamanho; j++) {
            if (i == 0 || i == tamanho - 1 || j == 0 || j == tamanho - 1) {
                printf("# ");
            } else {
                printf("  "); 
            }
        }
        printf("\n");
    }
    return 0;
}
