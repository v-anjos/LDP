# include <stdio.h>
# include <stdlib.h>

//escolha caso (Switch case)

int main(){
	int contagem, numero, soma;
	float media, n;
	scanf("%d", &numero);
	
	soma = 0;
	contagem = 1;
	
	while(contagem <= numero){
		printf("\nDigite o %do. numero: ", contagem);
		scanf("%f", &n);
		soma = soma + n;
		contagem = contagem + 1;
	}
	
	media = soma/numero ;
	printf("\nO a media eh: %.2f", media);
	return 0;
}
