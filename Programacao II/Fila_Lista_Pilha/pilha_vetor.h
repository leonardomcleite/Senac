#include <stdio.h>

typedef struct{
  int vetor[10];
  int topo;
} PilhaV;

void inicializar(PilhaV *p){
  p->topo=0;
}

int vazia(PilhaV *p){
  if(p->topo==0){
    return 1;
  }
  return 0;
}

int cheia(PilhaV *p){
  if(p->topo>=10){
    return 1;
  }
  return 0;
}

void inserir(PilhaV *p, int valor){
  if(cheia(p)==1){
    printf("ERRO: Pilha cheia\n");
    return;
  }
  p->vetor[p->topo]=valor;
  p->topo++;
}

int remover(PilhaV *p){
  if(vazia(p)==1){
    printf("ERRO: pilha vazia\n");
    return;
  }
  p->topo--;
  return p->vetor[p->topo];
}

void imprimir(PilhaV *p){
  for(int i=0; i<p->topo; i++){
    printf("%d ", p->vetor[i]);
  }
  printf("\n");
}