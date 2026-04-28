#include <stdio.h>

int main() {
    int i, j, soma, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) { //percorrer as linhas
        for (j = 1; j <= n; j++) { //preencher as linha
        	soma = i + j; //somar linhas e colunas
            if(soma % 2 == 0){ // imprimir caracter # soma par
            printf("#");	
			}else{
				printf("."); // imprimir caracter . soma impar
			}
        }
      printf("\n");//pular linhas
    }
    return 0;
}
