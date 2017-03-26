#include <stdlib.h>
#include <stdio.h>


typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
} FilaTipoItem;

typedef struct TipoCelula {
  FilaTipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;



void FFVazia(TipoFila *Fila)
{ 
  Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int FVazia(TipoFila Fila){ 
  return (Fila.Frente == Fila.Tras); 
} 

void FEnfileira(FilaTipoItem x, TipoFila *Fila){ 
  Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void FDesenfileira(TipoFila *Fila, FilaTipoItem *Item){ 
  TipoApontador q;
  if (FVazia(*Fila)) { 
    printf("Erro: fila esta vazia\n"); 
  return; 
}
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
} 

void Imprime(TipoFila Fila){ 
  TipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL){ 
    printf("%d\n", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
}



int main(int argc, char **argv)
{
	TipoFila fila;
	FilaTipoItem Fitem;
	int chave;
	int opc = 6;
	while(opc != 0){
			printf("\n\nFILA\n\n");
			printf("1-Esvaziar fila \n");
			printf("2-Inserir Elemento na fila \n");
			printf("3-Remover Elemento da fila \n");
			printf("4-Verificar se a fila esta vazia: \n");
			printf("5-Imprime a fila");
			printf("0-Voltar \n");
			scanf("%d",&opc);
			
			//FFVazia(&fila); // incializando a fila vazia
			switch (opc){

					case 1:
						FFVazia(&fila);
					break;
					 
					case 2:
						scanf("%d",&chave);
						Fitem.Chave = chave;
						FEnfileira(Fitem, &fila);
						printf ("Elemento %d Inserido na fila\n",chave);
					break;
					
					case 3:
						FDesenfileira(&fila,&Fitem);
						printf("Desempilhado: %d\n", Fitem.Chave);
					break;
				
					case 4:
						FVazia(fila);
					break;
					
					case 5:
						Imprime(fila);
					break;
				}
	}
	return 0;
}

