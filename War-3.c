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
//prototicos das funçoes
//funçoes que main ira chamar quando precisar
void  entradaDeDados();//
void  limparBufferEntrada();//
void  momentoDeAtaque();//
void  exibirmenu();//
void  condiçaoDeVitoria();
void  ExibirMapa();//
void  limparMemoria(struct territorio *territorios,char* destino,char* missoes,char* totaldeMissoes);//
void  atribuirmissoes();

int main(){

char* destino;
char* missoes[5];
char* totaldeMissoes;
char tiposdeMissoes = {"conquiste 3 territorios","consquiste o territorio 3","conquiste 2 territorios","conquister o territorio 5","conquiste todos os territorios"};

missoes[5] = &tiposdeMissoes;

struct territorio *territorios = (struct territorio *) calloc(Numero_Territorio, sizeof(struct territorio));

int totalDeTerritorios = 0;//variavel pra amarzena as structs territorios
int opçao;;//variavel para menu
entradaDeDados(territorios, &totalDeTerritorios);
atribuirmissoes();

do
{
  ExibirMapa(territorios, &totalDeTerritorios);
  exibirmenu();
  scanf("%d", &opçao);
  limparBufferEntrada();


  switch (opçao)
  {
  case 1 ://ataque
   momentoDeAtaque(territorios, totalDeTerritorios);

    break;
  
  case 2 ://verificar missao

    break;

  case 3 ://sair
    printf("=== saiu do sistema ===\n");
    break;

  default:
    printf("==== opçao invalidar ====\n");
    break;
  }

} while (opçao != 0);

limparMemoria(territorios,destino,missoes,totaldeMissoes);

return 0;
}


void  atribuirmissoes(){
char* destino;
char* missoes[5];
char* totaldeMissoes;

missoes[5] = (char*) malloc(sizeof(char));
destino = &missoes[rand() % 5];
}

//funçao para o ataque
void  momentoDeAtaque(int* opçaoDEF,int* opçaoATC ){
 
  int ataque, defesa;

    struct territorio *territorios;
    printf("-> escolha quem vai atacar: ");
    scanf("%d", opçaoATC);
    printf("\n");
    printf("-> escolha quem vai defender: ");
    scanf("%d", opçaoDEF);
    printf("\n");

    ataque = rand() % 10;//ataque recebe valor aleatorio
    defesa = rand() % 10;//defesa recebe valor aleatorio
    printf("\n");

    if (ataque > defesa)// vai comparar os valores de ataque e defesa e efetua oq vai sai
     {
      territorios[*opçaoDEF -= 1].tropa;//ataque ganha o territorio da defesa recebe menos 1 tropa
     }else{
       territorios[*opçaoATC -= 1].tropa -= 1;//defesa ganha o territorio de ataque recebe menos 1 tropa
     }
     printf("-ataque recebe: %d\n", ataque);//mostra o valor de ataque
     printf("-defesa recebe: %d\n", defesa);//mostra o valor de defesa
}

//funçao pra limpar o buff
void limparBufferEntrada(){
        int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//exibir o mapa de como o usuario digito
void  ExibirMapa(struct territorio *territorios, int *totalDeTerritorios)
{
    for (int i = 0; i < totalDeTerritorios; i++)
{
   printf("territorio %d\n -nome: %s -cor: %s -tropas: %d\n");
   printf("-nome: %s", territorios[i].nome);
   printf("-cor: %s", territorios[i].cor);
   printf("-tropa: %d", territorios[i].tropa);
   printf("=============================\n");
}
printf("\n");
}

//exibir o menu
void  exibirmenu(){
printf("=============================\n");
printf("== Batalhas de territorios ==\n");
printf("=============================\n");
printf("--- opçao 1: atacar ---\n");
printf("--- opçao 2: verificar missao ---\n");
printf("--- opçao 0: sair ---\n");
}

//a entrada de dados dos territorios
void  entradaDeDados(struct territorio *territorios, int *totalDeTerritorios)
{
for (int i = 0; i < Numero_Territorio; i++)
{
    printf("==== territorio %d ==== \n", i + 1);

    printf("Digite o Nome do Territorio: ");//pedindo pra digita algo
    fgets(territorios[*totalDeTerritorios].nome, Nome_Territorio, stdin); //armazenando as do nome do territorio 1

    printf("Digite a Cor do Territorio: ");//pedindo pra digita algo
    fgets(territorios[*totalDeTerritorios].cor, Nome_de_Cor, stdin); //armazena a cor do territorio 1

    printf("Digite a Quantidade de Tropas: ");//pedindo pra digita algo
    scanf("%d", &territorios[*totalDeTerritorios].tropa); //armazena a quantidade de tropas do territorio 1
    totalDeTerritorios++;
    limparBufferEntrada();
    printf("\n");
}
}

//libera a memoria
void  limparMemoria(struct territorio *territorios,char* missoes,char* destino,char* totaldeMissoes){
    free(territorios);
    free(destino );
    free(missoes);
    free(totaldeMissoes);
    printf("--- memorio liberada ---");
}