#include <stdio.h>
 
int main() {
int codigo, qtd;
float preco;

scanf("%d %d", &codigo, &qtd);
    if (codigo == 1)
    {
        preco = 4.0;
        printf("Total: R$ %.2f\n", qtd * preco);
    } else if (codigo == 2)
    {
        preco = 4.5;
        printf("Total: R$ %.2f\n", qtd * preco);
    }else if (codigo == 3)
    {
        preco = 5.0;
        printf("Total: R$ %.2f\n", qtd * preco);
    }else if (codigo == 4)
    {
        preco = 2.0;
        printf("Total: R$ %.2f\n", qtd * preco);
    }else if (codigo == 5)
    {
        preco = 1.5;
        printf("Total: R$ %.2f\n", qtd * preco);
    }else{
        printf("Codigo invalido\n");
    }
 
    return 0;
}
