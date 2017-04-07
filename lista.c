#include <stdlib.h>
#include <stdio.h>

/* ========================================================================= */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipolItem;

typedef struct LTipoCelula *LTipoApontador;

typedef struct LTipoCelula {
  TipolItem Item;
  LTipoApontador Prox;
} LTipoCelula;

typedef struct {
  LTipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista){ 
  Lista -> Primeiro = (LTipoApontador) malloc(sizeof(LTipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista){ 
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipolItem x, TipoLista *Lista){ 
  Lista -> Ultimo -> Prox = (LTipoApontador) malloc(sizeof(LTipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(LTipoApontador p, TipoLista *Lista, TipolItem *Item){
 /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  LTipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL) 
  { printf(" Erro Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

LTipoApontador Busca(TipoLista Lista, int chave){ 
  LTipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) { 
      if (Aux->Item.Chave==chave){
        printf(" Achou: %d\n", Aux->Item.Chave);
        return Aux;
      }  
      Aux = Aux -> Prox;
    }
    return NULL;
}

void LImprime(TipoLista Lista){ 
  LTipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}

/* ========================================================================== */

int main(){
 
    TipolItem item;
    TipoLista lista;
    int chave;
    LTipoApontador p;
    
    
    FLVazia(&lista);
   

    int opc = 6;
    while(opc != 0){

        printf("\n\n LISTA \n\n");
        printf("[1] Esvaziar Lista\n");
        printf("[2] Inserir Elemento na Lista\n");
        printf("[3] Remover Elemento da Lista de uma posicao (Remove o proximo)!\n");
        printf("[4] Verificar se a lista esta vazia:\n");
        printf("[5] Imprimir a lista\n");
        printf("[0] Voltar\n");
        scanf("%d",&opc);
    
        switch (opc){
            case 1:
                FLVazia(&lista);
            break;

            case 2:
                scanf("%d", &chave);
                item.Chave = chave;
                Insere(item, &lista);
            break;

            case 3:
                scanf("%d", &chave);
                p = Busca(lista, chave);
                Retira(p, &lista, &item);
            break;

            case 4:
                if (Vazia(lista))
                    printf("A lista está vazia\n");
                else
                    printf("A lista não está vazia\n");
            break;

            case 5:
                LImprime(lista);
            break;
        }
    }
}
