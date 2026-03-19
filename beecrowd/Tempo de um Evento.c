#include <stdio.h>

int main() {
    int d1, h1, m1, s1;
    int d2, h2, m2, s2;

    scanf("Dia %d", &d1);
    scanf("%d : %d : %d", &h1, &m1, &s1);

    scanf(" Dia %d", &d2); // espaço importante
    scanf("%d : %d : %d", &h2, &m2, &s2);

    int inicio = d1 * 86400 + h1 * 3600 + m1 * 60 + s1;
    int fim    = d2 * 86400 + h2 * 3600 + m2 * 60 + s2;

    int total = fim - inicio;

    int dias = total / 86400;
    total %= 86400;

    int horas = total / 3600;
    total %= 3600;

    int minutos = total / 60;
    int segundos = total % 60;

    printf("%d dia(s)\n", dias);
    printf("%d hora(s)\n", horas);
    printf("%d minuto(s)\n", minutos);
    printf("%d segundo(s)\n", segundos);

    return 0;
}
