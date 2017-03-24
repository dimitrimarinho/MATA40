#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

void FFVazia(TipoFila *Fila)
{ 
  Fila->Frente = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int Vazia(TipoFila Fila){ 
  return (Fila.Frente == Fila.Tras); 
} 

void Enfileira(TipoItem x, TipoFila *Fila){ 
  Fila->Tras->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipoItem *Item){ 
  TipoApontador q;
  if (Vazia(*Fila)) { 
    printf("Erro fila esta vazia\n"); 
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
