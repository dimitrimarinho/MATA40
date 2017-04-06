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
	}
	return 0;
}