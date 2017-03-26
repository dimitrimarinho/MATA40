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
int Pesquisa (ARV a , int b){
	if (Vazia(a)){
		printf("Erro: Registro nao esta presente na arvore!!\n");
		return 0;
	}else if ( a->chave == b ){
			printf("Está na arvore");
		 	return 1;
 		}else if ( b > a->chave )
 				return Pesquisa (a->dir, b);
 			else 
				return Pesquisa (a->esq, b);
				
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

void Remove (ARV raiz, int x ){
	ARV aux;
		if (raiz==NULL){
			printf("Erro : Elemento não esta na arvore!\n");
			return ;
		}
		else if(raiz->chave < x){
			Remove(raiz->esq,x);
			return;
		}
		else if(raiz->chave > x){
			Remove(raiz->dir,x);
			return;
		}
		else if (raiz->dir == NULL){
			aux=raiz;
			raiz = raiz->esq;
			free(aux);
			return;
		}
		else if(raiz->esq != NULL){
			Antecessor(raiz->esq,raiz );
			return;
			aux = raiz;
			raiz= raiz->dir;
			free(aux);
		}	
	}
//Função para percorrer a árvore respeitando o critério EM ORDEM
void inOrder (ARV a){
	if (!Vazia(a)){
		if((a->esq) != NULL)
			inOrder(a->esq);
		printf(" %d ", a->chave);
		if((a->dir) != NULL)
			inOrder(a->dir);
	}
}
	//Função para percorrer a árvore respeitando o critério PRÉ ORDEM
void preOrder (ARV a){
	if (!Vazia(a)){
		printf(" %d ", a->chave);
		if((a->esq) != NULL)
			preOrder(a->esq);
		if((a->dir) != NULL)
			preOrder(a->dir);
	}
}
	//Função para percorrer a árvore respeitando o critério POS ORDEM
void posOrder (ARV a){
	if (!Vazia(a)){
		if((a->esq) != NULL)
			posOrder(a->esq);
		if((a->dir) != NULL)
			posOrder(a->dir);
		printf(" %d ", a->chave);
	}
}

int main(int argc, char **argv){
	ARV arv;
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
				Pesquisa(arv, arv->chave);
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
