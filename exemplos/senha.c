#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM_PALAVRA 5
#define MAX_TENTATIVAS 5

struct Jogador {
    char nome[50];
    int pontuacao;
};

void mostrarRegras() {
    printf("\n========== REGRAS ==========\n");
    printf("1. O jogo escolhe uma palavra secreta de 5 letras.\n");
    printf("2. Voce possui 5 tentativas para adivinhar.\n");
    printf("3. Sera informado:\n");
    printf("   - Letras corretas na posicao certa.\n");
    printf("   - Letras existentes em posicao errada.\n");
    printf("4. Quanto menos tentativas usar,\n");
    printf("   maior sera sua pontuacao.\n");
    printf("============================\n\n");
}

void jogar() {
    struct Jogador jogador;

    char palavras[][6] = {
        "papel",
        "livro",
        "carro",
        "pedra",
        "carta",
        "praia",
        "verde",
        "ponto",
        "cinto",
        "folha"
    };

    char historico[MAX_TENTATIVAS][6] = {""};

    int quantidadePalavras =
        sizeof(palavras) / sizeof(palavras[0]);

    int indice = rand() % quantidadePalavras;

    char senha[6];
    strcpy(senha, palavras[indice]);

    printf("\nDigite seu nome: ");
    getchar(); // limpa buffer
    fgets(jogador.nome, 50, stdin);
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';

    jogador.pontuacao = 0;

    int venceu = 0;

    for (int tentativa = 0;
         tentativa < MAX_TENTATIVAS;
         tentativa++) {

        char palavra[6];

        printf("\nTentativa %d de %d\n",
               tentativa + 1,
               MAX_TENTATIVAS);

        printf("Digite uma palavra de 5 letras: ");
        scanf("%5s", palavra);

        strcpy(historico[tentativa], palavra);

        int certas = 0;
        int foraLugar = 0;

        for (int i = 0; i < TAM_PALAVRA; i++) {

            if (palavra[i] == senha[i]) {
                certas++;
            }
            else {

                for (int j = 0; j < TAM_PALAVRA; j++) {

                    if (palavra[i] == senha[j]) {
                        foraLugar++;
                        break;
                    }
                }
            }
        }

        printf("Corretas: %d\n", certas);
        printf("Posicao errada: %d\n", foraLugar);

        if (strcmp(palavra, senha) == 0) {

            venceu = 1;

            jogador.pontuacao =
                (MAX_TENTATIVAS - tentativa) * 20;

            printf("\nPARABENS! VOCE ACERTOU!\n");
            break;
        }
    }

    printf("\n===== HISTORICO =====\n");

    for (int i = 0; i < MAX_TENTATIVAS; i++) {

        if (strlen(historico[i]) > 0)
            printf("%d - %s\n",
                   i + 1,
                   historico[i]);
    }

    if (venceu) {

        printf("\nJogador: %s\n",
               jogador.nome);

        printf("Pontuacao: %d\n",
               jogador.pontuacao);
    }
    else {

        printf("\nVOCE PERDEU!\n");
        printf("Palavra secreta: %s\n",
               senha);
    }

    printf("\n");
}

int main() {

    int opcao;

    srand(time(NULL));

    do {

        printf("=================================\n");
        printf("          SENHA C\n");
        printf("=================================\n");
        printf("1 - Jogar\n");
        printf("2 - Ver Regras\n");
        printf("3 - Sair\n");
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
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 3);

    return 0;
}
