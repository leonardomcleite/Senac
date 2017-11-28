#include <stdio.h>

typedef struct N{
  int valor;
  struct N *proximo;
} node;

typedef struct{
  node *inicio;
  node *fim;
}Fila;

void inicializaPilha(Fila *p){
  p->fim=NULL;
  p->inicio = NULL;
}

int vazia(Fila *p){
  if(p->inicio==NULL){
    return 1;
  }
  return 0;
}

void inserir(Fila *p, int valor_adicionado){
  node *no;
  no =(node *)malloc(sizeof(node));
  no->valor=valor_adicionado;
  no->proximo= NULL;

  if(vazia(p)==1)
    p->inicio = no;
  else
    p->fim->proximo = no;
    
  p->fim = no;
}

int remover(Fila *p){
  if(vazia(p)==1){
    printf("ERRO: pilha vazia\n");
    return;
  }
  node *temp;
  temp=p->inicio;
  p->inicio=p->inicio->proximo;
  return temp->valor;
}

void imprimePilha(Fila *p){
  node *temp;
  temp=p->inicio;
  while(temp!=NULL){
    printf("%d ", temp->valor);
    temp=temp->proximo;
  }
  printf("\n");
}