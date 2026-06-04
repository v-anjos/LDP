#include <stdio.h>

void boas_vindas() {
	printf("-----Boas Vindas-----");
}

int realizar_venda(int *saldo, int valor_item, int valor_pago){
	*saldo += valor_item;
	int troco = valor_pago - valor_item; 
	return troco;
}

int verificar_caixa(int saldo) {
	if(saldo >= 199999){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int caixa = 100000;
	int troco = 0; 
	int i;	
	boas_vindas();
	
	for (i = 1; i <= 5000; i++){
		troco += realizar_venda(&caixa, 20, 25);
	}
	
	printf("\n%d", caixa/100);
	printf("\n%d", troco/100);
	
	i = verificar_caixa(caixa);
	if(i){
		printf("\nSucesso! O caixa bateu.\n");
	} else {
		printf("\nERRO! O caixa nao bateu devido a %.2lf\n", caixa/100);
	}
	return 0;
}
