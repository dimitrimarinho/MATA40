
#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista){ 
  Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int Vazia(TipoLista Lista){ 
	if(Lista.Primeiro == Lista.Ultimo)
		return (0);
	else
		return (1);
}

void Insere(TipoItem x, TipoLista *Lista){ 
  Lista -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> Item = x;
  Lista -> Ultimo -> Prox = NULL;
}

void InsereDepois(TipoApontador p, TipoItem x, TipoLista *Lista){
  TipoApontador aux = p->Prox;
  TipoApontador temp = (TipoApontador) malloc(sizeof(TipoCelula));
  p->Prox = temp;
  temp->Prox = aux;
  temp->Item = x;
  if (aux==NULL){
      Lista -> Ultimo = temp;
      printf("ok");
  }
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
 /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
  TipoApontador q;
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

TipoApontador Busca(TipoLista Lista, int chave){ 
  TipoApontador Aux;
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

void Imprime(TipoLista Lista){ 
  TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux -> Item.Chave);
      Aux = Aux -> Prox;
    }
}



int main(int argc, char **argv){
	
	TipoItem item;
    TipoLista lista;
    TipoApontador p;
	
	int chave,a;
	
	int opc = 6;
	while(opc != 0){

			printf("####### LISTA #######\n");
			printf("1-Esvaziar Lista\n");
			printf("2-Inserir Elemento na Lista\n");
			printf("3-Remover Elemento da Lista de uma posicao (Remove o proximo)!!\n");
			printf("4-Verificar se a lista esta vazia: 0-Vazia 1-Com elementos \n");
			printf("5-Imprimir a lista\n");
			printf("0-Voltar\n");
			scanf("%d",&opc);
		
			switch (opc){
	
			case 1:
				FLVazia(&lista);// incializando a lista vazia
			break;
			
			case 2:
				scanf("%d",&chave);
				item.Chave=chave;
				Insere(item, &lista);
			break;
			
			case 3:
				scanf("%d",&chave);
				item.Chave=chave;
				p = Busca(lista,chave);
				Retira(p, &lista, &item);
			break;
			
			case 4:
				a=Vazia(lista);
				printf("%d\n",a);
			break;
			
			case 5:
				Imprime(lista);
			break;
		
		break;
	}
	
	}
	return 0;
}
