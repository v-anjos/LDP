#include <stdio.h>
#include <string.h>

int main() {

    char coluna[20], tipo[20], oque_come[20];

    scanf("%s", coluna);
    scanf("%s", tipo);
    scanf("%s", oque_come);

    if (strcmp(coluna, "vertebrado") == 0) {

        if (strcmp(tipo, "ave") == 0) {

            if (strcmp(oque_come, "carnivoro") == 0)
                printf("aguia\n");
            else
                printf("pomba\n");

        } else { // mamifero

            if (strcmp(oque_come, "onivoro") == 0)
                printf("homem\n");
            else
                printf("vaca\n");
        }

    } else { // invertebrado

        if (strcmp(tipo, "inseto") == 0) {

            if (strcmp(oque_come, "hematofago") == 0)
                printf("pulga\n");
            else
                printf("lagarta\n");

        } else { // anelideo

            if (strcmp(oque_come, "hematofago") == 0)
                printf("sanguessuga\n");
            else
                printf("minhoca\n");
        }
    }

    return 0;
}
