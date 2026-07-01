#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PERGUNTAS 15
#define MAX_JOGADORES 10

//==============================
// STRUCT JOGADOR
//==============================

typedef struct{

    char nome[50];

    int premio;

    int acertos;

    int erros;

}Jogador;

//==============================
// STRUCT PERGUNTA
//==============================

typedef struct{

    char pergunta[200];

    char A[100];

    char B[100];

    char C[100];

    char D[100];

    char correta;

    int premio;

    int nivel;

}Pergunta;


Jogador ranking[MAX_JOGADORES];
int totalRanking = 0;
char historico[15][50];

Pergunta perguntas[MAX_PERGUNTAS]={


{
"Qual linguagem estamos estudando?",
"Java",
"C",
"Python",
"PHP",
'B',
1000,
1
},

{
"Qual comando imprime na tela?",
"printf",
"scanf",
"fgets",
"gets",
'A',
2000,
1
},

{
"Qual biblioteca possui printf?",
"stdio.h",
"string.h",
"stdlib.h",
"time.h",
'A',
3000,
1
},

{
"Qual comando lê dados?",
"scanf",
"printf",
"for",
"switch",
'A',
5000,
1
},

{
"Qual estrutura cria repetição?",
"char",
"float",
"for",
"if",
'C',
10000,
1
},

{
"Qual biblioteca trabalha com strings?",
"stdlib.h",
"string.h",
"stdio.h",
"time.h",
'B',
20000,
2
},

{
"Qual comando compara strings?",
"==",
"strcmp",
"strcpy",
"strlen",
'B',
30000,
2
},

{
"Qual comando copia strings?",
"strlen",
"strcmp",
"strcpy",
"scanf",
'C',
50000,
2
},

{
"Qual comando conta caracteres?",
"strcpy",
"strlen",
"strcmp",
"sizeof",
'B',
80000,
2
},

{
"Qual biblioteca gera números aleatórios?",
"math.h",
"stdlib.h",
"string.h",
"ctype.h",
'B',
100000,
2
},

{
"O operador && significa:",
"OU",
"E",
"IGUAL",
"DIFERENTE",
'B',
200000,
3
},

{
"Qual função converte para maiúscula?",
"toupper",
"tolower",
"strcmp",
"printf",
'A',
300000,
3
},

{
"Qual função inicializa o rand()?",
"time()",
"scanf()",
"srand()",
"printf()",
'C',
500000,
3
},

{
"Qual comando encerra uma função?",
"break",
"continue",
"return",
"goto",
'C',
750000,
3
},

{
"Quanto vale o prêmio máximo?",
"500.000",
"750.000",
"1.000.000",
"900.000",
'C',
1000000,
3
}

};


void regras(){

    printf("\n===============================\n");
    printf("           REGRAS\n");
    printf("===============================\n");

    printf("1 - Responda A B C ou D.\n");

    printf("2 - Cada pergunta aumenta o prêmio.\n");

    printf("3 - Um erro encerra o jogo.\n");

    printf("4 - Existem 3 ajudas:\n");

    printf("   U - Universitarios\n");

    printf("   E - Eliminar duas alternativas\n");

    printf("   P - Pular pergunta\n");

    printf("5 - Cada ajuda pode ser usada apenas uma vez.\n");

}

void creditos(){

    printf("\n===============================\n");

    printf("SHOW DO MILHÃO EM C\n");

    printf("Projeto desenvolvido por Vinicius de Araujo dos Anjos para\n");

    printf("disciplina de Linguagens de Programação.\n");

    printf("===============================\n");

}

void universitarios(char correta){

    char opcoes[4] = {'A','B','C','D'};

    printf("\n========== UNIVERSITARIOS ==========\n");

    for(int i=0;i<3;i++){

        int chance = rand()%100;

        if(chance < 75){

            printf("Universitario %d: Acho que a resposta e %c\n",
                    i+1,
                    correta);

        }else{

            char sugestao;

            do{

                sugestao = opcoes[rand()%4];

            }while(sugestao == correta);

            printf("Universitario %d: Acho que a resposta e %c\n",
                    i+1,
                    sugestao);

        }

    }

    printf("====================================\n");

}

void eliminarAlternativas(char correta,
                          int *A,
                          int *B,
                          int *C,
                          int *D){

    int removidas = 0;

    while(removidas < 2){

        int r = rand()%4;

        if(r==0 && correta!='A' && *A){

            *A = 0;
            removidas++;

        }

        if(r==1 && correta!='B' && *B){

            *B = 0;
            removidas++;

        }

        if(r==2 && correta!='C' && *C){

            *C = 0;
            removidas++;

        }

        if(r==3 && correta!='D' && *D){

            *D = 0;
            removidas++;

        }

    }

}

void jogar(){

    Jogador jogador;

    jogador.premio = 0;
    jogador.acertos = 0;
    jogador.erros = 0;

    getchar();

    printf("\nDigite seu nome: ");

    fgets(jogador.nome,50,stdin);

    jogador.nome[strcspn(jogador.nome,"\n")] = '\0';

    int ajudaUniversitario = 1;
    int ajudaEliminar = 1;
    int ajudaPular = 1;

    int historicoPos = 0;

    printf("\nBoa sorte %s!\n",jogador.nome);

    for(int nivel=1;nivel<=3;nivel++){

        for(int i=0;i<MAX_PERGUNTAS;i++){

            if(perguntas[i].nivel != nivel)
                continue;

            int mostrarA=1;
            int mostrarB=1;
            int mostrarC=1;
            int mostrarD=1;

            int respondeu=0;

            while(!respondeu){

                printf("\n========================================\n");

                printf("Premio: R$ %d\n",
                       perguntas[i].premio);

                printf("Nivel: %d\n",
                       perguntas[i].nivel);

                printf("========================================\n\n");

                printf("%s\n\n",
                       perguntas[i].pergunta);

                if(mostrarA)
                    printf("A) %s\n",perguntas[i].A);

                if(mostrarB)
                    printf("B) %s\n",perguntas[i].B);

                if(mostrarC)
                    printf("C) %s\n",perguntas[i].C);

                if(mostrarD)
                    printf("D) %s\n",perguntas[i].D);

                printf("\n");

                if(ajudaUniversitario)
                    printf("U - Universitarios\n");

                if(ajudaEliminar)
                    printf("E - Eliminar duas alternativas\n");

                if(ajudaPular)
                    printf("P - Pular pergunta\n");

                printf("\nResposta: ");

                char resp;

                scanf(" %c",&resp);

                resp = toupper(resp);
                //ajuda
                if(resp=='U'){

                    if(ajudaUniversitario){

                        universitarios(perguntas[i].correta);

                        ajudaUniversitario=0;

                    }else{

                        printf("\nAjuda ja utilizada!\n");

                    }

                    continue;

                }
                //eliminar
                if(resp=='E'){

                    if(ajudaEliminar){

                        eliminarAlternativas(
                        perguntas[i].correta,
                        &mostrarA,
                        &mostrarB,
                        &mostrarC,
                        &mostrarD);

                        ajudaEliminar=0;

                    }else{

                        printf("\nAjuda ja utilizada!\n");

                    }

                    continue;

                }
                //pular
                if(resp=='P'){

                    if(ajudaPular){

                        printf("\nPergunta pulada!\n");

                        strcpy(historico[historicoPos],
                               "Pergunta pulada");

                        historicoPos++;

                        ajudaPular=0;

                        respondeu=1;

                    }else{

                        printf("\nAjuda ja utilizada!\n");

                    }

                    continue;

                }
                //correto?
                if(resp == perguntas[i].correta){

                    printf("\nCORRETO!!\n");

                    jogador.acertos++;

                    jogador.premio = perguntas[i].premio;

                    strcpy(historico[historicoPos],
                           "Resposta Correta");

                    historicoPos++;

                    respondeu=1;

                }else{

                    printf("\nERRADO!\n");

                    printf("Resposta correta: %c\n",
                            perguntas[i].correta);

                    jogador.erros++;

                    strcpy(historico[historicoPos],
                           "Resposta Errada");

                    historicoPos++;

                    printf("\nPremio Final: R$ %d\n",
                            jogador.premio);

                    if(totalRanking < MAX_JOGADORES){

                        ranking[totalRanking] = jogador;
                        totalRanking++;

                    }

                    return;

                }

            }

        }

    }

    printf("\n========================================\n");

    printf("PARABENS %s\n",jogador.nome);

    printf("VOCE GANHOU O SHOW DO MILHAO!\n");

    printf("Premio Final: R$ %d\n",jogador.premio);

    printf("Acertos: %d\n",jogador.acertos);

    printf("Erros: %d\n",jogador.erros);

    printf("========================================\n");

    if(totalRanking < MAX_JOGADORES){

        ranking[totalRanking] = jogador;

        totalRanking++;

    }

}

//historico

void mostrarHistorico(int quantidade){

    printf("\n====================================\n");
    printf("HISTORICO DA PARTIDA\n");
    printf("====================================\n");

    for(int i=0;i<quantidade;i++){

        printf("Pergunta %d -> %s\n",
                i+1,
                historico[i]);
    }

}

//ordem placar
void ordenarRanking(){

    Jogador aux;

    for(int i=0;i<totalRanking-1;i++){

        for(int j=i+1;j<totalRanking;j++){

            if(ranking[j].premio > ranking[i].premio){

                aux = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = aux;

            }

        }

    }

}

//mostra placar
void mostrarRanking(){

    ordenarRanking();

    printf("\n====================================\n");
    printf("RANKING\n");
    printf("====================================\n");

    if(totalRanking==0){

        printf("Nenhum jogador cadastrado.\n");

        return;

    }

    for(int i=0;i<totalRanking;i++){

        printf("\n%d Lugar\n",i+1);

        printf("Nome: %s\n",
               ranking[i].nome);

        printf("Premio: R$ %d\n",
               ranking[i].premio);

        printf("Acertos: %d\n",
               ranking[i].acertos);

        printf("Erros: %d\n",
               ranking[i].erros);

    }

}

void menu(){

    int op;

    do{

        printf("\n=====================================\n");
        printf("       SHOW DO MILHAO EM C\n");
        printf("=====================================\n");
        printf("1 - Jogar\n");
        printf("2 - Regras\n");
        printf("3 - Ranking\n");
        printf("4 - Creditos\n");
        printf("5 - Sair\n");
        printf("=====================================\n");
        printf("Escolha: ");

        scanf("%d",&op);

        switch(op){

            case 1:

                jogar();

                break;

            case 2:

                regras();

                break;

            case 3:

                mostrarRanking();

                break;

            case 4:

                creditos();

                break;

            case 5:

                printf("\nObrigado por jogar!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");

        }

    }while(op!=5);

}

int main(){

    srand(time(NULL));

    menu();

    return 0;

}
