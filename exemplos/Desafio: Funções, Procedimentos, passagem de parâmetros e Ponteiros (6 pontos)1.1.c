#include <stdio.h>

void boas_vindas() {
	printf("-----Boas Vindas-----");
}

double arredondar_2_casas(double valor) {
    return ((int)(valor * 100.0 + 0.5)) / 100.0;
}

double realizar_venda(double *saldo, double valor_item, double valor_pago){
	*saldo = arredondar_2_casas(*saldo + valor_item);
	
	double troco = valor_pago - valor_item; 
	return arredondar_2_casas(troco);
}

int verificar_caixa(double saldo) {
	if(saldo >= (1999.99 - 0.00001)){
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
		troco = arredondar_2_casas(troco + realizar_venda(&caixa, 0.20, 0.25));
	}
	
	printf("\n%.50lf", caixa);
	printf("\n%.50lf", troco);
	
	i = verificar_caixa(caixa);
	if(i){
		printf("\nSucesso! O caixa bateu.\n");
	} else {
		printf("\nERRO! O caixa nao bateu devido a %.2lf\n", caixa);
	}
	return 0;
}
