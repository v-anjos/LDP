#include <stdio.h>

int main() {
    int i, j, w, n;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (w = 1; w <= i; w++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
