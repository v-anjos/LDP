#include <stdio.h>

int main() {
    int A, B, i;
    
    scanf("%d %d", &A, &B);
    

    	for(A = 1; A<=B; A++){
    		for(i=1; i<=10; i++){
    			printf("\n%d X %d = %d", A, i, A*i);
			}
		}



    return 0;
}
