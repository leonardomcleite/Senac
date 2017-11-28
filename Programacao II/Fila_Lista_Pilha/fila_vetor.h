#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct{
  int tamanho;
  int vetor[tam];
  int topo;
  int inicio;
} FilaV;

void inicializar(FilaV *p){
  p->tamanho = 0;
  p->topo = 0;
  p->inicio = 0;
}

int cheio(FilaV *p) {
  if(p->topo > tam - 1)
    return 1;
  return 0;
}

int vazio (FilaV *p) {
  if(p->tamanho == 0)
      return 1;
  return 0;
}

void inserir(FilaV *p, int valor) {
  if(cheio(p) == 1 && p->tamanho != tam) {
    p->topo = 0;
    p->vetor[p->topo] = valor;
    p->tamanho++;
    p->topo++;
  }
  else if (p->tamanho == tam){
    printf("ERRO: Fila cheia\n");
    return;
  } else
  {
    p->vetor[p->topo] = valor;
    p->topo++;
    p->tamanho++;
  }
}

int remover(FilaV *p){
  if(vazio(p) == 1) {
    printf("ERRO: Fila vazia\n");
    return;
  }
  p->tamanho--;
  p->inicio++;
  return p->vetor[p->inicio];
}

void imprimir(FilaV *p){
  int i;
  int temp=0;
  int k = p->inicio;
  for(i=0; i<p->tamanho; i++){
    printf("%d ", p->vetor[k]);
    k++;
    if(k > tam - 1)
    {
      temp = p->inicio;
      p->inicio = 0;
      p->vetor[p->topo];
      k = 0;
    }
  }
  printf("\n");
}
