#include <stdio.h>

int main() {

    int n, contpar=0, i;

    for ( i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            contpar++;
        }
        
    }
    
    printf("%d valores pares\n", contpar);


    return 0;
}
