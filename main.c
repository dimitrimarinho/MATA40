#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "fila.c"

int main(int argc, char **argv)
{
	TipoItem item;
    TipoFila fila;
    int chave,opc;
    
    printf("O que deseja usar?\n\n 1-Lista\n 2-Pilha\n 3-Pilha\n 4-Arvore\n\n");
    scanf("%d",&opc);
    switch (opc){
		case 3:
		printf("FILA\n\n");
		//printf("Escolha uma opcao: \n");
		printf("1-Esvaziar fila \n");
		printf("2-Inserir Elemento na fila\n ");
		printf("3-Remover Elemento da fila \n ");
		printf("4-Verificar se a fila esta vazia: \n");
		
		scanf("%d",&opc);
		FFVazia(&fila); // incializando a pilha vazia
		switch (opc){
				case 1:
					FFVazia(&fila);
				break;
				 
				case 2:
					// loop para quantos elementos deseja inserir
					scanf("%d",&chave);
					item.Chave = chave;
					Enfileira(item, &fila);
					printf ("Elemento %d Inserido\n",chave);
				break;
				
				case 3:
					Desenfileira(&fila, &item);
					printf("Desempilhado: %d\n", item.Chave);
				break;
				
				case 4:
					printf("Em manutencao");
				break;
			}
   }

   
    
    /*
    item.Chave = 88;
    Enfileira(item, &fila);
    
    item.Chave = 17;
    Enfileira(item, &fila);
    
    Imprime(fila);
    
    */
    

     	

    Imprime(fila);
	return 0;
}
