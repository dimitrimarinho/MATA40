#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAX 10

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipopItem;

typedef struct PilhaTipoCelula *PilhaTipoApontador;

typedef struct PilhaTipoCelula {
  TipopItem pItem;
  PilhaTipoApontador Prox;
} PilhaTipoCelula;

typedef struct {
  PilhaTipoApontador Fundo, Topo;
  int Tamanho;
} TipoPilha;

void FPVazia(TipoPilha *Pilha){
  Pilha->Topo = (PilhaTipoApontador) malloc(sizeof(PilhaTipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 

int PVazia(TipoPilha Pilha){ 
  return (Pilha.Topo == Pilha.Fundo);
} 

void Empilha(TipopItem x, TipoPilha *Pilha){
  PilhaTipoApontador Aux;
  Aux = (PilhaTipoApontador) malloc(sizeof(PilhaTipoCelula));
  Pilha->Topo->pItem = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
} 

void Desempilha(TipoPilha *Pilha, TipopItem *pItem){
  PilhaTipoApontador q;
  if (PVazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *pItem = q->Prox->pItem;
  free(q);  Pilha->Tamanho--;
} 

int Tamanho(TipoPilha Pilha){
  return (Pilha.Tamanho); 
} 

/*---Fila---*/

typedef struct FilaTipoCelula *FilaTipoApontador;

typedef int TipoChave;

typedef struct TipofItem {
  TipoChave Chave;
  /* outros componentes */
} TipofItem;

typedef struct FilaTipoCelula {
  TipofItem Item;
  FilaTipoApontador Prox;
} FilaTipoCelula;

typedef struct TipoFila {
  FilaTipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila){
  Fila->Frente = (FilaTipoApontador) malloc(sizeof(FilaTipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int Vazia(TipoFila Fila){
  return (Fila.Frente == Fila.Tras); 
} 

void Enfileira(TipofItem x, TipoFila *Fila){
  Fila->Tras->Prox = (FilaTipoApontador) malloc(sizeof(FilaTipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->Item = x;
  Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipofItem *Item){
  FilaTipoApontador q;
  if (Vazia(*Fila)) { printf("Erro fila esta vazia\n"); return; }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->Item;
  free(q);

} 

void Imprime(TipoFila Fila){
  FilaTipoApontador Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux->Item.Chave);
      Aux = Aux->Prox;
    }
}

/* LISTA */

typedef int TipoChave;

typedef struct {
  int Chave;
  /* outros componentes */
} TipolItem;

typedef struct LTipoCelula *LTipoApontador;

typedef struct LTipoCelula {
  TipolItem lItem;
  LTipoApontador Prox;
} LTipoCelula;

typedef struct {
  LTipoApontador Primeiro, Ultimo;
} TipoLista;

/* ========================================================================= */

void FLVazia(TipoLista *Lista){ 
  Lista -> Primeiro = (LTipoApontador) malloc(sizeof(LTipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

int LVazia(TipoLista Lista){ 
  return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipolItem x, TipoLista *Lista){ 
  Lista -> Ultimo -> Prox = (LTipoApontador) malloc(sizeof(LTipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> lItem = x;
  Lista -> Ultimo -> Prox = NULL;
}

void Retira(LTipoApontador p, TipoLista *Lista, TipolItem *lItem){
 /*  ---   Obs.: o litem a ser retirado e  o seguinte ao apontado por  p --- */
  LTipoApontador q;
  if (LVazia(*Lista) || p == NULL || p -> Prox == NULL) 
  { printf(" Erro Lista vazia ou posicao nao existe\n");
    return;
  }
  q = p -> Prox;
  *lItem = q -> lItem;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}

LTipoApontador Busca(TipoLista Lista, int chave){ 
  LTipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) { 
      if (Aux->lItem.Chave==chave){
        printf(" Achou: %d\n", Aux->lItem.Chave);
        return Aux;
      }  
      Aux = Aux -> Prox;
    }
    return NULL;
}

void LImprime(TipoLista Lista){ 
  LTipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) 
    { printf("%d\n", Aux -> lItem.Chave);
      Aux = Aux -> Prox;
    }
}
