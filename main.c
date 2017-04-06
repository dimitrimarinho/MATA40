#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipopItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipopItem pItem;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha){
  Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 

int PVazia(TipoPilha Pilha){ 
  return (Pilha.Topo == Pilha.Fundo);
} 

void Empilha(TipopItem x, TipoPilha *Pilha){
  TipoApontador Aux;
  Aux = (TipoApontador) malloc(sizeof(TipoCelula));
  Pilha->Topo->pItem = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
} 

void Desempilha(TipoPilha *Pilha, TipopItem *pItem){
  TipoApontador q;
  if (PVazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *pItem = q->Prox->pItem;
  free(q);  Pilha->Tamanho--;
} 

int Tamanho(TipoPilha Pilha){
  return (Pilha.Tamanho); 
} 


int main(){
  TipopItem pitem;
  TipoPilha pilha;
  int chave;

  FPVazia(&pilha);

  int opc = 6;

  while(opc != 0){
    printf("\n\nPILHA\n\n");
    printf("[1] Esvaziar pilha \n");
    printf("[2] Inserir Elemento na pilha \n");
    printf("[3] Remover Elemento da pilha \n");
    printf("[4] Verificar se a pilha esta vazia: \n");
    printf("[5] Informa tamanho da pilha\n");
    printf("[0] Voltar \n");
    scanf("%d",&opc);

    switch (opc){

      case 1:
      FPVazia(&pilha);
      break;

      case 2:
      scanf("%d", &chave);
      pitem.Chave = chave;
      Empilha(pitem, &pilha);
      break;

      case 3:
        Desempilha(&pilha, &pitem);
        printf("Desempilhado: %d\n", pitem.Chave);

      break;

      case 4:
        if (PVazia(pilha))
          printf("Pilha Vazia\n");

        else 
            printf("Pilha não vazia\n");
      break;

      case 5:
        printf("Tamanho: %d\n", Tamanho(pilha));
      break;

      return 0;
    }
  }
}