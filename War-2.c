#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Constantes Globais
#define Nome_Territorio  30
#define Nome_de_Cor  10
#define Numero_Territorio  5

//definiçao da estrutura (struct)
struct territorio {
    char nome[Nome_Territorio];
    char cor[Nome_de_Cor];
    int tropa;
};

//funçao para limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//funçao principal
int main() {
struct territorio *territorios;
int totaldeTerritorios = 0;//indica a quantidade de territorio que por enquanto e 0
int opçao1 , opçao2;//escolha da opçoes
int ataque, defesa;//valores que vai retribir o numero aleatorio


territorios = (struct territorio *) calloc (Numero_Territorio, sizeof(struct territorio));
//testo inicial
printf("=========================\n");
printf(" Cadastro de Territorio\n");
printf("=========================\n");
printf("\n");
/*
loop pra recebe os dados das informaçoes dos territorios.
(i + 1)na linha 46 pra indicar o numero dos territorios pos sem o +1 serio (0 pra 4) em vez de ( 1 pra 5).
totalterritorio vai ganha incremento pra define as quantidas de territorios.
depois limpa a buff de entrada pra nao da erro.
*/
for (int i = 0; i < Numero_Territorio; i++)
{
    printf("==== territorio %d ==== \n", i + 1);

    printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
    fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin); //armazenando as do nome do territorio 1

    printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
    fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin); //armazena a cor do territorio 1

    printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
    scanf("%d", &territorios[totaldeTerritorios].tropa); //armazena a quantidade de tropas do territorio 1
    totaldeTerritorios++;
    limparBufferEntrada();
    printf("\n");
}
//testeo pra incia a epçao de ataca ou sai
printf("==== Momento do atque =======\n");

/*
um loop onde enqunto for i menor que totaldeTerritorios vai imprimir a barra de codegos do loop.
a valor do totaldeterritorios e ganhado nos encrementos nos codegos acima.
i vai endica tbm a posiçao das informaçoes nos vetores.
e vai imprimir territorio com seus respectivos dados entregados pelo usuario(territo: x,nome: x,cor: x,tropa: x)
*/
for (int i = 0; i < totaldeTerritorios; i++)
{
   printf("territorio %d\n -nome: %s -cor: %s -tropas: %d\n", i + 1,territorios[i].nome, territorios[i].cor, territorios[i].tropa);
   printf("=============================\n");
}
printf("\n");

//loop pra fazer a fase de ataque ou saida do programa
do
{
   printf("->escolha de (1 a 5) pra atacar ou (0) pra sair: ");//escolha do usuario pra sai ou territorio ataca
   scanf("%d", &opçao1);//recebe a resposta

   if (opçao1 > 0 && opçao1 < 6)//funçao pra se caso o jogar escolhe 0,nao afetua ou se escolher 1 ou 5,inicia o proceso de ataque
   {

     printf("->Escolha entre (1 a 5): ");//escolha qual territorio defender
     scanf("%d", &opçao2);//recebe a resposta
    printf("\n");

    ataque = rand() % 10;//ataque recebe valor aleatorio
    defesa = rand() % 10;//defesa recebe valor aleatorio
    printf("\n");

     if (ataque > defesa)// vai comparar os valores de ataque e defesa e efetua oq vai sai
     {
       territorios[opçao2 - 1].tropa -= 1;//ataque ganha o territorio da defesa recebe menos 1 tropa
     }else{
        territorios[opçao1 - 1].tropa -= 1;//defesa ganha o territorio de ataque recebe menos 1 tropa
     }
     printf("-ataque recebe: %d\n", ataque);//mostra o valor de ataque
     printf("-defesa recebe: %d\n", defesa);//mostra o valor de defesa
   }
//vai imprimir tudo com os valores modificado com quem perde no ataque
 for (int i = 0; i < totaldeTerritorios; i++){
   printf("territorio %d\n -nome: %s -cor: %s -tropas: %d\n", i + 1,territorios[i].nome, territorios[i].cor, territorios[i].tropa);
   printf("=============================\n");
}

} while (opçao1 > 0 && opçao1 < 6);

printf("==== voce saiu====\n");//pra aparece que saiu

free(territorios);// libera a memoria
printf("==== Memoria liberada =====");
}