#include <stdio.h>

int main() {

    int T, N;
    unsigned long long fib[61];

    // primeiros termos
    fib[0] = 0;
    fib[1] = 1;

    // preenche o vetor fibonacci
    for (int i = 2; i <= 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &N);

        printf("Fib(%d) = %llu\n", N, fib[N]);
    }

    return 0;
}
