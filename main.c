#include <stdlib.h>
#include <stdio.h>

typedef struct TipoCelula *TipoApontador;

typedef int TipoChave;

typedef struct TipoItem {
  TipoChave Chave;
} FilaTipoItem;

typedef struct TipoCelula {
  FilaTipoItem Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
  TipoApontador Frente, Tras;
} TipoFila;


void FFVazia(TipoFila *Fila)
{ 
  Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int FVazia(TipoFila Fila){ 
  return (Fila.Frente == Fila.Tras); 
} 

void FEnfileira(FilaTipoItem x, TipoFila *Fila){ 
  Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void FDesenfileira(TipoFila *Fila, FilaTipoItem *Item){ 
  TipoApontador q;
  if (FVazia(*Fila)) { 
    printf("Erro: fila esta vazia\n"); 
  return; 
}
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);
} 

void Imprime(TipoFila Fila){ 
  TipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL){ 
    printf("%d\n", Aux->Item.Chave);
    Aux = Aux->Prox;
  }
}

