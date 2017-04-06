#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "library.h"
#define MAX 10

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