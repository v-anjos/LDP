#include <stdio.h>

void boas_vindas() {
	printf("-----Boas Vindas-----");
}

double realizar_venda(double *saldo, double valor_item, double valor_pago){
	*saldo += valor_item;
	double troco = valor_pago - valor_item; 
	return troco;
}

int verificar_caixa(double saldo) {
	if(saldo >= 1999.99){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	double caixa = 1000.00;
	double troco = 0.0; 
	int i;	
	boas_vindas();
	
	for (i = 1; i <= 5000; i++){
		troco += realizar_venda(&caixa, 0.20, 0.25);
	}
	
	printf("\n%.2lf", caixa);
	printf("\n%.2lf", troco);
	
	i = verificar_caixa(caixa);
	if(i){
		printf("\nSucesso! O caixa bateu.\n");
	} else {
		printf("\nERRO! O caixa nao bateu devido a %.2lf\n", caixa);
	}
	return 0;
}
