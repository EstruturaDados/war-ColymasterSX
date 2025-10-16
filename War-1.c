#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
struct territorio territorios[Numero_Territorio];//criando um struct pra armazena todas os 5 teritorios
int totaldeTerritorios = 0;//indica a quantidade de territorio que por enquanto e 0

//testo inicial
printf("=========================\n");
printf(" Cadastro de Territorio\n");
printf("=========================\n");
printf("\n");


//entrada do territorio 1
printf("====== 1-Territorio ======\n");

printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin); //armazenando as do nome do territorio 1

printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin); //armazena a cor do territorio 1

printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
scanf("%d", &territorios[totaldeTerritorios].tropa); //armazena a quantidade de tropas do territorio 1
printf("\n");

totaldeTerritorios++;//incrementando +1 na variavel
limparBufferEntrada();

//entrada do territorio 2
printf("====== 2-Territorio ======\n");

printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin);//armazenando as do nome do territorio 2

printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin);//armazena a cor do territorio 2

printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
scanf("%d", &territorios[totaldeTerritorios].tropa);//armazena a quantidade de tropas do territorio 2
printf("\n");

totaldeTerritorios++;//incrementando +1 na variavel
limparBufferEntrada();

//entrada do territorio 3
printf("====== 3-Territorio ======\n");

printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin);//armazenando as do nome do territorio 3

printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin);//armazena a cor do territorio 3

printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
scanf("%d", &territorios[totaldeTerritorios].tropa);//armazena a quantidade de tropas do territorio 3
printf("\n");

totaldeTerritorios++;//incrementando +1 na variavel
limparBufferEntrada();

//entrada do territorio 4
printf("====== 4-Territorio ======\n");

printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin);//armazenando as do nome do territorio 4

printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin);//armazena a cor do territorio 4

printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
scanf("%d", &territorios[totaldeTerritorios].tropa);//armazena a quantidade de tropas do territorio 4
printf("\n");

totaldeTerritorios++;//incrementando +1 na variavel
limparBufferEntrada();

//entrada do territorio 5
printf("====== 5-Territorio ======\n");

printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].nome, Nome_Territorio, stdin);//armazenando as do nome do territorio 5

printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
fgets(territorios[totaldeTerritorios].cor, Nome_de_Cor, stdin);//armazena a cor do territorio 5

printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
scanf("%d", &territorios[totaldeTerritorios].tropa);//armazena a quantidade de tropas do territorio 5
printf("\n");

totaldeTerritorios++;//incrementando +1 na variavel
limparBufferEntrada();

/*
um loop onde enqunto for i menor que totaldeTerritorios vai imprimir a barra de codegos do loop.
a valor do totaldeterritorios e ganhado nos encrementos nos codegos acima.
i vai endica tbm a posiçao das informaçoes nos vetores.
e vai imprimir territorio com seus respectivos dados entregados pelo usuario(territo: x,nome: x,cor: x,tropa: x)
*/
for (int i = 0; i < totaldeTerritorios; i++)
{
   printf("==================\n");
   printf("---territorio %d---\n", i + 1);
   printf("-Nome: %s\n",territorios[i].nome);
   printf("-Cor: %s\n", territorios[i].cor);
   printf("-Tropas: %d\n", territorios[i].tropa);
}
printf("==================\n");

return 0;
}