
#include <stdlib.h>
#include <stdio.h>

typedef int ListaTipoChave;

typedef struct {
  int Chave;
} ListaTipoItem;

typedef struct ListaTipoCelula *ListaTipoApontador;

typedef struct ListaTipoCelula {
  ListaTipoItem Item;
  ListaTipoApontador Prox;
} ListaTipoCelula;

typedef struct {
  ListaTipoApontador Primeiro, Ultimo;
} TipoLista;




void FLVazia(TipoLista *Lista){ 
  Lista -> Primeiro = (ListaTipoApontador) malloc(sizeof(ListaTipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int LVazia(TipoLista Lista){ 
  return (Lista.Primeiro == Lista.Ultimo);
}

void LInsere(ListaTipoItem x, TipoLista *Lista){ 
  Lista -> Ultimo -> Prox = (ListaTipoApontador) malloc(sizeof(ListaTipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
  printf("Elemento %d Inserido\n",x.Chave);
  return;
}

void LRetira(ListaTipoApontador p, TipoLista *Lista, ListaTipoItem *Item){ /*---Obs.: o item a ser retirado e o seguinte ao apontado por  p --- */
  ListaTipoApontador q;
  if (LVazia(*Lista) || p == NULL || p -> Prox == NULL){ 
    printf(" Erro:  Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

void LImprime(TipoLista Lista){ 
  ListaTipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL){ 
    printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
  }
}



int main(int argc, char **argv){
	TipoLista lista;
	ListaTipoItem Litem;
	ListaTipoApontador Lp=NULL;
	
	int chave;
	
	int opc = 6;
	while(opc != 0){

			printf("LISTA\n\n");
			printf("1-Esvaziar Lista\n");
			printf("2-Inserir Elemento na Lista\n");
			printf("3-Remover Elemento da Lista de uma posicao\n");
			printf("4-Verificar se a lista esta vazia\n");
			printf("5-Imprimir a lista\n");
			printf("0-Voltar\n");
			scanf("%d",&opc);
			
			//FLVazia(&lista); // incializando a lista vazia
			
			switch (opc){
	
			case 1:
				FLVazia(&lista);
			break;
			
			case 2:
				scanf("%d",&chave);
				Litem.Chave=chave;
				LInsere(Litem, &lista);
			break;
			
			case 3:
				LRetira(Lp, &lista, &Litem);//REVERRRRR
			break;
			
			case 4:
				if (LVazia(lista)){
					printf("Lista Vazia\n");
					return (0);
				}
				else
					printf("Lista Nao Vazia\n");
					return (1);	
			break;
			
			case 5:
				LImprime(lista);
			break;
		
		break;
	}
	
	}
	return 0;
}
