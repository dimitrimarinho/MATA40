#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "curses.h"
#include "fila.c"
#include "pilha.c"
#include "lista.c"
#include "arvore.c"

int main(int argc, char **argv)
{ 
	TipoFila fila;
	TipoPilha pilha;
	TipoLista lista;
	
	PilhaTipoItem Pitem;
	FilaTipoItem Fitem;
	ListaTipoItem Litem;
	
	NO a;
	ListaTipoApontador Lp=NULL;
   
   
   
    int chave,opc=0;
    menu:
		printf("O que deseja usar?\n\n");
		printf("[1] Lista\n" );
		printf("[2] Pilha\n" );
		printf("[3] Fila\n" );
		printf("[4] Arvore de Busca\n" );
		printf("[10] Documentacao\n" );
	  
    scanf("%d",&opc);

	
  
    switch (opc){
		case 1:
		opc=0;
			printf("LISTA\n\n");
		
			printf("1-Esvaziar Lista \n");
			printf("2-Inserir Elemento na Lista\n ");
			printf("3-Remover Elemento da Lista de uma posicao \n ");
			printf("4-Verificar se a lista esta vazia: \n");
			printf("5-Imprimir a lista \n");
			printf("0-Voltar \n");
			scanf("%d",&opc);
			case 0:
				goto menu;
				break;
		
			
			FLVazia(&lista); // incializando a lista vazia
			
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
		}
		break;
		case 2:
		opc=0;

			printf("PILHA\n\n");
			printf("1-Esvaziar Pilha \n");
			printf("2-Inserir Elemento na Pilha\n ");
			printf("3-Remover Elemento da Pilha \n ");
			printf("4-Verificar se a pilha esta vazia: \n");
			
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
						printf("Em manutencao");
					break;
					
					case 10:
						printf("Em manutencao");
					break;
				}
		break;
		
		
		
		
	case 3:
		opc=0;
			printf("FILA\n\n");
			printf("1-Esvaziar fila \n");
			printf("2-Inserir Elemento na fila\n ");
			printf("3-Remover Elemento da fila \n ");
			printf("4-Verificar se a fila esta vazia: \n");
			
			scanf("%d",&opc);
			FFVazia(&fila); // incializando a fila vazia
			switch (opc){
					case 1:
						FFVazia(&fila);
					break;
					 
					case 2:
						scanf("%d",&chave);
						Fitem.Chave = chave;
						FEnfileira(Fitem, &fila);
						printf ("Elemento %d Inserido\n",chave);
					break;
					
					case 3:
						FDesenfileira(&Fitem,&fila);
						printf("Desempilhado: %d\n", Fitem.Chave);
					break;
				
					case 4:
						printf("Em manutencao");
					break;
					
					case 10:
						printf("Em manutencao");
					break;
				}
	break;
   
	case 4:
		opc=0;
			printf("ARVORE BINARIA\n\n");
			printf("1-Iniciar uma arvore \n");
			printf("2-Pesquisar elemento na arvore\n ");
			printf("3-Inserir elemento na arvore\n ");
			printf("4-Remover elemento da arvore: \n");
			printf("5-Imprimir arvore: \n");
		switch (opc){
			case 1:	
				Inicializa(&a);
			break;
			case 2:
				scanf("%d",&chave);
				Pesquisa(&a,chave);
			break;
			case 3:
				scanf("%d",&chave);
				insere(&a,chave);
			break;
			case 4:
				scanf("%d",&chave);
				Remove(&a,chave);
				
			case 5:
				printf("Em Ordem: \n");
				inOrder(&a);
				printf("Pre Ordem: \n");
				preOrder(&a);
				printf("Pos Ordem: \n");
				posOrder(&a);
			break;
		}
		break;

}
    
    /*
    item.Chave = 88;
    Enfileira(item, &fila);
    
    item.Chave = 17;
    Enfileira(item, &fila);
    
    Imprime(fila);
    
    */
    

     	

  //  Imprime(fila);
	return 0;
}

