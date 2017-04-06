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
			printf("%d Está na arvore",b);
		 	return ;
 		}else if ( b > a->chave ){
 				return Pesquisa (a->dir, b);
 			}else {
				return Pesquisa (a->esq, b);
			}	
} 

//Funçõa para remover um elemento da arvoe
ARV Remove (ARV raiz, int x ){
	ARV aux = raiz;
	ARV q,r;
		if (raiz==NULL){
			printf("Erro : Elemento não esta na arvore!\n");
			return NULL;
		}
		else if( x < aux->chave ){
			aux->esq = Remove(aux->esq,x);
			
		}
		else if( x > aux->chave){
			aux->dir = Remove(aux->dir,x);
			
		}
		else {
			if(aux->esq == NULL && aux->dir == NULL){	
				free(aux);
				aux=NULL;
				printf ("Removido %d \n",x);
			return aux;
		}
	
		// no só com um filho a esquerda
		else if (aux->dir == NULL){
			q=aux;
			aux = aux->esq;
			free(q);
			printf ("Removido %d \n",x);
		}
		// no só com um filho a direita
		else if (aux->esq == NULL){
			q=aux;
			aux = aux->dir;
			free(q);
			printf ("Removido %d \n",x);
		}
	
		 else { // no tem os dois filhos
			r = aux->esq;
			while(r->dir !=NULL){
				r=r->dir;
				}
				aux->chave = r->chave;
				r->chave = x;
				aux->esq = Remove(aux->esq, x);
				printf ("Removido %d \n",x);
			}
		}
			
		
		return aux;
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
			printf("\n####### ARVORE BINARIA #######\n\n");
			printf("1-Iniciar uma arvore \n");
			printf("2-Pesquisar elemento na arvore \n");
			printf("3-Inserir elemento na arvore \n");
			printf("4-Remover elemento da arvore \n");
			printf("5-Imprimir arvore (Em Ordem) \n");
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
				arv = Remove(arv,chave);
				break;
				
			case 5:
				printf("\nEm Ordem: ");
				inOrder(arv);
				
			break;
			}
	}
	return 0;
}
