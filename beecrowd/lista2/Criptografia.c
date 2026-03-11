#include <stdio.h>
#include <string.h>

int main() {

    int N;
    char texto[1005];

    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++) {

        fgets(texto, sizeof(texto), stdin);

        int len = strlen(texto);

        if(texto[len-1] == '\n'){
            texto[len-1] = '\0';
            len--;
        }

        // PASSO 1
        for(int j = 0; j < len; j++){
            if((texto[j] >= 'a' && texto[j] <= 'z') || 
               (texto[j] >= 'A' && texto[j] <= 'Z')){
                texto[j] += 3;
            }
        }

        // PASSO 2 (inverter)
        for(int j = 0; j < len/2; j++){
            char temp = texto[j];
            texto[j] = texto[len-1-j];
            texto[len-1-j] = temp;
        }

        // PASSO 3
        for(int j = len/2; j < len; j++){
            texto[j] -= 1;
        }

        printf("%s\n", texto);
    }

    return 0;
}
