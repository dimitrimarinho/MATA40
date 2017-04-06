#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
 int chave;
 struct nodo *esq;
 struct nodo *dir;
} NO;

typedef NO *ARV;

int Vazia (ARV a){
	return (a == NULL);
} 

void Inicializa(ARV *a){ 
	(*a) = NULL;
	printf("Arvore Inicializada\n");
}

// Criar arvore vazia
void CriarArvore(ARV *a){
	ARV nova;
		nova = (ARV) malloc (sizeof(ARV));
 		nova->esq = NULL;
 		nova->dir = NULL;
 		(*a) = nova;
 	printf("Arvore criada!\n\n");
}

// Função para inserir um novo elemento 'b' na arvore 'a'
void insere (ARV *a, int b) { 
	ARV nova;
	
 	if (Vazia((*a))){
 		nova = (ARV) malloc (sizeof(ARV));
 		nova->chave = b;
 		nova->esq = NULL;
 		nova->dir = NULL;
 		(*a) = nova;
 		printf("Insercao do numero %d na AB realizada!\n\n", b);
	} else{ 
		if ( b > (*a)->chave )
			insere(&(*a)->dir, b);
		else if ( b < (*a)->chave )
			insere(&(*a)->esq, b);
		else printf("Erro : Registro ja existe na arvore\n");
	}
} 

// Função para procurar um elemento numa arvore
void Pesquisa (ARV a , int b){
	if (a==NULL){
		printf("Erro: Registro nao esta presente na arvore!!\n");
		return ;
	}else if ( a->chave == b ){
			printf("Está na arvore");
		 	return ;
 		}else if ( b > a->chave ){
 				return Pesquisa (a->dir, b);
 			}else {
				return Pesquisa (a->esq, b);
			}	
} 

//Funcao remover elemento da arvore
void Antecessor(ARV raiz, ARV r){
	
	if(r->dir != NULL){
		Antecessor(raiz,r->dir);
		return;
	}
	raiz->chave = r->chave;
	raiz = r;
	r=r->esq;
	free(raiz);
}

ARV Remove (ARV raiz, int x ){
	ARV aux = raiz;
		if (raiz==NULL){
			printf("Erro : Elemento não esta na arvore!\n");
			return NULL;
		}
		else if( aux->chave > x ){
			Remove(aux->esq,x);
			return NULL;
		}
		else if( aux->chave < x){
			Remove(aux->dir,x);
			return NULL;
		}
		//nó sem filho
		else if ( x == aux->chave ){ 
				if(aux->esq == NULL && aux->dir==NULL)		
				free(aux);
				aux=NULL;
				printf ("OI 1\n");
			return aux;
		}
		
		
		// no só com um filho a esquerda
		else if (raiz->dir == NULL){
			aux = aux->esq;
			free(aux);
			printf ("OII 2\n");
		}
		// no só com um filho a direita
		else if (raiz->esq == NULL){
			aux = aux->dir;
			free(aux);
			printf ("OIII 3\n");
		} else { // no tem os dois filhos
			aux = raiz->esq;
			while(aux->dir !=NULL){
				aux=aux->dir;
				}
				raiz->chave = aux->chave;
				aux->chave = x;
				raiz->esq = Remove(raiz->esq, x);
				printf ("OIII 4\n");
			}
		
			return raiz;
		
	}
//Função para percorrer a árvore respeitando o critério EM ORDEM
void inOrder (ARV raiz){
	if ((raiz)==NULL)
		return;
	else{
		inOrder(raiz->esq);
		printf(" %d ", raiz->chave);
		inOrder(raiz->dir);
	}
	
}
int main(int argc, char **argv){
	ARV arv=NULL;
	int chave;
	
	int opc = 6;
	while(opc != 0){
			opc=0;
			printf("\nARVORE BINARIA\n\n");
			printf("1-Iniciar uma arvore \n");
			printf("2-Pesquisar elemento na arvore\n ");
			printf("3-Inserir elemento na arvore\n ");
			printf("4-Remover elemento da arvore: \n");
			printf("5-Imprimir arvore: \n");
			printf("0-Sair \n");
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
				Remove(arv,chave);
				break;
				
			case 5:
				printf("\nEm Ordem: ");
				inOrder(arv);
				printf("\nPre Ordem: ");
				preOrder(arv);
				printf("\nPos Ordem: ");
				posOrder(arv);
			break;
			}
	}
	return 0;
}
