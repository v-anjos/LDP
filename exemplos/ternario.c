# include <stdio.h>

//versão if else simplificada b = a > 0? -150 : 150;
// serve para fazer um if else mais resumido, operador ternario
int main(){
	char ch;
	scanf("%c", &ch);
	
	if (ch == '0'){
		printf("Zero");
	}else if(ch == '1'){
		printf("Um");
	}else if(ch == '2'){
		printf("Dois");
	}else if(ch == '3'){
		printf("Três");
	}else if(ch == '4'){
		printf("Quatro");
	}else if(ch == '5'){
		printf("Cinco");
	}else if(ch == '6'){
		printf("Seis");
	}else if(ch == '7'){
		printf("Sete");
	}else if (ch == '8'){
		printf("Oito");
	}else if(ch == '9'){
		printf("Nove");
	}else{
		printf("Nao era um digito!");
	}
	return 0;
}
