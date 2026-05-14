#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                int valor = i > j ? i - j + 1 : j - i + 1;

                if (j == 0)
                    printf("%3d", valor);
                else
                    printf(" %3d", valor);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
