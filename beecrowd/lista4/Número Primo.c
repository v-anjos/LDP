#include <stdio.h>

int main() {

    int n, x, i, j, primo;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        primo = 1; // assume que é primo

        for(j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                primo = 0;
                break;
            }
        }

        if(primo)
            printf("%d eh primo\n", x);
        else
            printf("%d nao eh primo\n", x);
    }

    return 0;
}
