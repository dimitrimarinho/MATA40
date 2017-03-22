#include <stdlib.h>
#include <stdio.h>

int Vazia (ARV a){
	return (a == NULL);
} 

void Inicializa(ARV a){ 
	a = NULL;
}

// Função para inserir um novo elemento 'b' na arvore 'a'
ARV insere (ARV a, int b) { 
	ARV nova;
	
 	if (Vazia(a)){
 		nova = (ARV) malloc (sizeof(NO));
 		nova->chave = b;
 		nova->esq = NULL;
 		nova->dir = NULL;
 		printf("Insercao do numero %d na AB realizada!", b);
 		return nova;
 } else{ 
 		if ( b > a->chave )
 			a->dir = insere(a->dir, b);
		else
			if ( b < a->chave )
 				a->esq = insere(a->esq, b);
 			else printf("Erro : Registro ja existe na arvore\n");
 		
		return a;
 }
} 


// Função para procurar um elemento numa arvore
ARV Pesquisa (ARV a , int b){
	if (Vazia(a)){
		printf("Erro: Registro nao esta presente na arvore\n");
		return NULL;
	}else
 		if ( a->chave == b )
		 	return a;
 		else
 			if ( b > a->chave )
 				return Pesquisa (a->dir, b);
 			else 
				return Pesquisa (a->esq, b);
} 


//Função para percorrer a árvore respeitando o critério EM ORDEM
void inOrder (ARV a){
 if (!Vazia(a)){
 	inOrder(a->esq);
 	printf(" %d ", a->chave);
 	inOrder(a->dir);
 }

	//Função para percorrer a árvore respeitando o critério PRÉ ORDEM
void preOrder (ARV a){
 if (!Vazia(a)){
	printf(" %d ", a->chave);
 	preOrder(a->esq);
 	preOrder(a->dir);
 }
	//Função para percorrer a árvore respeitando o critério POS ORDEM
void posOrder (ARV a){
 if (!Vazia(a)){
 	posOrder(a->esq);
 	posOrder(a->dir);
	printf(" %d ", a->chave);
 }
	
} 
