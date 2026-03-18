#include <stdio.h>

int main() {
    int hi, mi, hf, mf;
    int inicio, fim, duracao;
    int horas, minutos;

    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    // converter tudo para minutos
    inicio = hi * 60 + mi;
    fim = hf * 60 + mf;

    // calcular duração
    if (fim > inicio) {
        duracao = fim - inicio;
    } else {
        duracao = (24 * 60 - inicio) + fim;
    }

    // converter de volta para horas e minutos
    horas = duracao / 60;
    minutos = duracao % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);

    return 0;
}
