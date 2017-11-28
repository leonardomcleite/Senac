#include <stdio.h>

typedef struct N{
  int valor;
  struct N *proximo;
} node;

typedef struct{
  node *topo;
}Pilha;

void inicializar(Pilha *p){
  p->topo=NULL;
}

int vazia(Pilha *p){
  if(p->topo==NULL){
    return 1;
  }
  return 0;
}

int cheia(Pilha *p){
  if(p->topo>=10){
    return 1;
  }
  return 0;
}

void inserir(Pilha *p, int valor){
  node *no;
  no=(node *)malloc(sizeof(node));
  no->valor=valor;
  no->proximo=p->topo;
  p->topo=no;
}

int remover(Pilha *p){
  if(vazia(p)==1){
    printf("ERRO: pilha vazia\n");
    return;
  }
  node *temp;
  temp=p->topo;
  p->topo=p->topo->proximo;
  return temp->valor;
}

void imprimir(Pilha *p){
  node *temp;
  temp=p->topo;
  while(temp!=NULL){
    printf("%d ", temp->valor);
    temp=temp->proximo;
  }
  printf("\n");
}