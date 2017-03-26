
#include <stdio.h>
#include <stdlib.h>


typedef int PilhaTipoChave;

typedef struct {
  int Chave;
} PilhaTipoItem;

typedef struct PilhaTipoCelula *PilhaTipoApontador;

typedef struct PilhaTipoCelula {
  PilhaTipoItem Item;
  PilhaTipoApontador Prox;
} PilhaTipoCelula;

typedef struct {
  PilhaTipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;





void FPVazia(TipoPilha *Pilha){
  Pilha->Topo = (PilhaTipoApontador) malloc(sizeof(PilhaTipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 

int PVazia(TipoPilha Pilha){ 
  return (Pilha.Topo == Pilha.Fundo);
} 

void PEmpilha(PilhaTipoItem x, TipoPilha *Pilha){
  PilhaTipoApontador Aux;
  Aux = (PilhaTipoApontador) malloc(sizeof(PilhaTipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
} 

void PDesempilha(TipoPilha *Pilha, PilhaTipoItem *Item){
  PilhaTipoApontador q;
  if (PVazia(*Pilha)) { 
	  printf("Erro: lista vazia\n"); 
	  return;
	}
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  free(q);  
  Pilha->Tamanho--;
} 

int PTamanho(TipoPilha Pilha){
  return (Pilha.Tamanho); 
} 

int main(int argc, char **argv)
{
	TipoPilha pilha;
	PilhaTipoItem Pitem;
	
	int chave,opc=6;
	while(opc != 0){
			printf("\n\nPILHA\n\n");
			printf("1-Esvaziar Pilha\n");
			printf("2-Inserir Elemento na Pilha\n");
			printf("3-Remover Elemento da Pilha\n");
			printf("4-Verificar se a pilha esta vazia\n");
			printf("10-Documentacao\n");
			printf("0-Voltar\n");
			scanf("%d",&opc);
				
			FPVazia(&pilha); // incializando a pilha vazia
			switch (opc){
		
					case 1:
						FPVazia(&pilha);
					break;
					 
					case 2:
						scanf("%d",&chave);
						Pitem.Chave = chave;
						PEmpilha(Pitem, &pilha);
						printf ("Elemento %d Inserido\n",chave);
					break;
					
					case 3:
						PDesempilha(&pilha, &Pitem);
						printf("Desempilhado: %d\n", Pitem.Chave);
					break;
					
					case 4:
						PVazia(pilha);
					break;
					
					case 10:
						printf("Em manutencao");
					break;
				}
		}
	return 0;
}

