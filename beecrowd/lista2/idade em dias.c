#include <stdio.h>

int main(){
	
	int n, resto;
	scanf("%d", &n);
	
	resto = n;
	
	printf("%d ano(s)\n", resto / 365);
	resto %= 365;
	printf("%d mes(es)\n", resto / 30);
	resto %=30;
	printf("%d dia(s)\n", resto); 
	
	return 0;
}
