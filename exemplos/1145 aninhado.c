#include <stdio.h>

int main() {
    int x, y, i, j;
    scanf("%d %d", &x, &y);
    for (i = 1; i <= y; i += x) {       
        for (j = 0; j < x; j++) {
            if (i + j <= y) { 
                printf("%d ", i + j);                
                if (j == x - 1) printf("\n");
            }
        }
    }
    return 0;
}
