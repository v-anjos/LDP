#include <stdio.h>

int main() {

    int i, n;
    int pares = 0, impares = 0;
    int positivos = 0, negativos = 0;

    for(i = 0; i < 5; i++) {
        scanf("%d", &n);

        // par ou ímpar
        if(n % 2 == 0)
            pares++;
        else
            impares++;

        // positivo ou negativo
        if(n > 0)
            positivos++;
        else if(n < 0)
            negativos++;
    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", negativos);

    return 0;
}
