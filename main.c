#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "library.h"

int main(int argc, char **argv)
{ 
    TipofItem item;
    TipoFila fila;

    TipopItem pitem;
  	TipoPilha pilha;

    TipolItem litem;
    TipoLista lista;
    LTipoApontador p;

	ARV arv=NULL;
    

    int chave;
    int opc=0;
    menu:{
		printf("O que deseja usar?\n\n");
		printf("[1] Lista\n" );
		printf("[2] Pilha\n" );
		printf("[3] Fila\n" );
		printf("[4] Arvore de Binaria de Busca\n" );
		scanf("%d",&opc);
		printf("\e[1;1H\e[2J");
	}
  
    switch (opc){
		case 1:
		    FLVazia(&lista);

		    opc = 6;
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
		        	case 0:
		        		goto menu;
	        		break;
	        		
		            case 1:
		                FLVazia(&lista);
		            break;

		            case 2:
		                scanf("%d", &chave);
		                litem.Chave = chave;
		                Insere(litem, &lista);
		            break;

		            case 3:
		                scanf("%d", &chave);
		                p = Busca(lista, chave);
		                Retira(p, &lista, &litem);
		            break;

		            case 4:
		                if (LVazia(lista))
		                    printf("A lista está vazia\n");
		                else
		                    printf("A lista não está vazia\n");
		            break;

		            case 5:
		                LImprime(lista);
		            break;
		        }
		    }
		break;

		case 2:
			FPVazia(&pilha);

			opc = 6;

			while(opc != 0){
				printf("\n\nPILHA\n\n");
				printf("[1] Esvaziar pilha \n");
				printf("[2] Inserir Elemento na pilha \n");
				printf("[3] Remover Elemento da pilha \n");
				printf("[4] Verificar se a pilha esta vazia: \n");
				printf("[5] Informa tamanho da pilha\n");
				printf("[0] Voltar \n");
				scanf("%d",&opc);
				printf("\e[1;1H\e[2J");

				switch (opc){

					case 0:
						goto menu;
					break;

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
				}
			}
		break;
						
		case 3:
	    	FFVazia(&fila);

	   
	    	int opc = 6;

	    	while(opc != 0){
	        printf("\n\nFILA\n\n");
	        printf("[1] Esvaziar fila \n");
	        printf("[2] Inserir Elemento na fila \n");
	        printf("[3] Remover Elemento da fila \n");
	        printf("[4] Verificar se a fila esta vazia: \n");
	        printf("[5] Imprime a fila\n");
	        printf("[0] Voltar \n");
	        scanf("%d",&opc);
	        printf("\e[1;1H\e[2J");

	        switch (opc){
	        	case 0:
	        		goto menu;
	        	break;

	            case 1:
	                FFVazia(&fila);
	                break;

	            case 2:
	                scanf("%d", &chave);
	                item.Chave = chave;
	                Enfileira(item, &fila);
	            break;

	            case 3:
	                Desenfileira(&fila, &item);
	                printf("Desempilhado: %d\n", item.Chave);
	                break;

	            case 4:
	                if (Vazia(fila)){
	                    printf("Vazia\n");
	                } else {
	                    printf("Não vazia\n");
	                }
	                break;

	            case 5:
	                Imprime(fila);
	            break;
	        }
	    	}
		break;

		case 4:
			opc = 6;
			while(opc != 0){
				opc=0;
				printf("\n\n ARVORE BINARIA \n\n");
				printf("[1] Iniciar uma arvore \n");
				printf("[2] Pesquisar elemento na arvore \n");
				printf("[3] Inserir elemento na arvore \n");
				printf("[4] Remover elemento da arvore \n");
				printf("[5] Imprimir arvore (Em Ordem) \n");
				printf("[0] Voltar \n");
				scanf("%d",&opc);
			switch (opc){
				case 1:	
					Inicializa(&arv);				
				break;
				case 2:			
					scanf("%d",&chave);
					Pesquisa(arv,chave);
				break;
				case 3:
					scanf("%d",&chave);
					insere(&arv,chave);
				break;
				case 4:
					scanf("%d",&chave);
					arv = Remove(arv,chave);
					break;
					
				case 5:
					printf("\nEm Ordem: ");
					inOrder(arv);
					
				break;
			}
	}

		break;
	}
	return 0;
}