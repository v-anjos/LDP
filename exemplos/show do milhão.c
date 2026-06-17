#include <stdio.h>
#include <string.h>

struct Pergunta {
    char enunciado[200];
    char alternativaA[100];
    char alternativaB[100];
    char alternativaC[100];
    char alternativaD[100];
    char respostaCorreta;
    int premio;
};

void mostrarRegras() {
    printf("\n========== REGRAS ==========\n");
    printf("1. Responda as perguntas escolhendo A, B, C ou D.\n");
    printf("2. Cada acerto aumenta seu premio.\n");
    printf("3. Um erro encerra o jogo.\n");
    printf("4. Tente chegar ao premio maximo!\n");
    printf("============================\n\n");
}

void jogar() {

    char nome[50];
    char resposta;
    int premioTotal = 0;

    struct Pergunta perguntas[5] = {

        {
            "Qual linguagem estamos estudando nesta disciplina?",
            "Java",
            "C",
            "Python",
            "PHP",
            'B',
            1000
        },

        {
            "Qual comando exibe texto na tela em C?",
            "printf",
            "scanf",
            "fgets",
            "strcmp",
            'A',
            5000
        },

        {
            "Qual estrutura cria um tipo personalizado?",
            "for",
            "if",
            "struct",
            "switch",
            'C',
            10000
        },

        {
            "Qual comando e utilizado para repeticao?",
            "for",
            "char",
            "float",
            "struct",
            'A',
            50000
        },

        {
            "Qual biblioteca permite usar strcmp()?",
            "stdlib.h",
            "time.h",
            "string.h",
            "math.h",
            'C',
            100000
        }
    };

    getchar();

    printf("\nDigite seu nome: ");
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("\nBoa sorte, %s!\n", nome);

    for(int i = 0; i < 5; i++) {

        printf("\n=====================================\n");
        printf("Pergunta valendo R$ %d\n", perguntas[i].premio);
        printf("=====================================\n");

        printf("%s\n\n", perguntas[i].enunciado);

        printf("A) %s\n", perguntas[i].alternativaA);
        printf("B) %s\n", perguntas[i].alternativaB);
        printf("C) %s\n", perguntas[i].alternativaC);
        printf("D) %s\n", perguntas[i].alternativaD);

        printf("\nSua resposta: ");
        scanf(" %c", &resposta);

        if(resposta >= 'a' && resposta <= 'z')
            resposta -= 32;

        if(resposta == perguntas[i].respostaCorreta) {

            premioTotal = perguntas[i].premio;

            printf("\nCORRETO!\n");
            printf("Premio acumulado: R$ %d\n", premioTotal);
        }
        else {

            printf("\nRESPOSTA ERRADA!\n");
            printf("A alternativa correta era: %c\n",
                   perguntas[i].respostaCorreta);

            printf("\nFim de jogo!\n");
            printf("Voce saiu com R$ %d\n",
                   premioTotal);

            return;
        }
    }

    printf("\n=====================================\n");
    printf("PARABENS %s!\n", nome);
    printf("VOCE VENCEU O SHOW DO MILHAO!\n");
    printf("Premio final: R$ %d\n", premioTotal);
    printf("=====================================\n");
}

int main() {

    int opcao;

    do {

        printf("\n=================================\n");
        printf("       SHOW DO MILHAO ADS\n");
        printf("=================================\n");
        printf("1 - Jogar\n");
        printf("2 - Regras\n");
        printf("3 - Creditos\n");
        printf("4 - Sair\n");
        printf("=================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                jogar();
                break;

            case 2:
                mostrarRegras();
                break;

            case 3:
                printf("\nProjeto desenvolvido para a disciplina de Programacao em C.\n");
                break;

            case 4:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 4);

    return 0;
}
