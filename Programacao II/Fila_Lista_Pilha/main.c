//Pilha

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "pilha_encadeada.h"
//#include "pilha_vetor.h"
//#include "fila_encadeada.h"
//#include "fila_vetor.h"
//#include "lista_d_encadeada.h"

int main(){
  //Pilha minha_estrutura;
  //PilhaV minha_estrutura;
  //Fila minha_estrutura;
  //FilaV minha_estrutura;
  
  int temp;
  
  inicializar(&minha_estrutura);
  inserir(&minha_estrutura, 19);
  inserir(&minha_estrutura, 28);
  inserir(&minha_estrutura, 30);
  inserir(&minha_estrutura, 12);
  imprimir(&minha_estrutura);
  temp=remover(&minha_estrutura);
  temp=remover(&minha_estrutura);
  inserir(&minha_estrutura, 51);
  inserir(&minha_estrutura, 48);
  imprimir(&minha_estrutura);
}

/*
int main(){
  ListaD minha_estrutura;
  int temp;
  CriarLista(&minha_estrutura);

  inserirElemento(&minha_estrutura, 1, 4);
  inserirElemento(&minha_estrutura, 1, -2);
  inserirElemento(&minha_estrutura, -2, -2);
  imprimeLista(&minha_estrutura);
  temp=removerElemento(&minha_estrutura, 2, 2);
  imprimeLista(&minha_estrutura);
  testaObjeto(&minha_estrutura);
  return 0;
}
*/