#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include "library.h"
#define MAX 10


int main(){
    TipofItem item;
    TipoFila fila;
    int chave;
    
    
    FFVazia(&fila);

   
    int opc = 6;

    while(opc != 0){
        printf("\n\nFILA\n\n");
        printf("1-Esvaziar fila \n");
        printf("2-Inserir Elemento na fila \n");
        printf("3-Remover Elemento da fila \n");
        printf("4-Verificar se a fila esta vazia: \n");
        printf("5-Imprime a fila\n");
        printf("0-Voltar \n");
        scanf("%d",&opc);

        switch (opc){
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

/*item.Chave = 59;
    
    item.Chave = 88;
    Enfileira(item, &fila);
    
    item.Chave = 17;
    Enfileira(item, &fila);
    
    Imprime(fila);
    
    
    Desenfileira(&fila, &item);

     	printf("Desempilhado: %d\n", item.Chave);

    Imprime(fila);
     
*/
  return(0);
}