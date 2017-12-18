#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct N{
  float linha;
  float coluna;
  struct N *proximo;
  struct N *anterior;
} node;

typedef struct{
  node *topo;
  int cont;
}ListaD;

void CriarLista(ListaD *l){
  l->topo = NULL;
  l->cont = 0;
}

int ListaDVazia(ListaD *l){
  if(l->topo == NULL){
    return 1;
  }
  return 0;
}

void inserirElemento(ListaD *l, float linhaV, float colunaV){
  node *no;
  no =(node *)malloc(sizeof(node));
  no->linha = linhaV;
  no->coluna = colunaV;
  no->anterior = NULL;
  no->proximo = NULL;

  if(ListaDVazia(l)==1){
    l->topo = no;
  } else
  {
    no->anterior = l->topo;
    l->topo->proximo = no;
    l->topo = no;
  }

  l->cont++;
}

int removerElemento(ListaD *l, float linhaV, float colunaV){
  int entrou = 0;
  node *temp;
  node *temp2;
  temp = l->topo;
  temp2 = l->topo;

  if(ListaDVazia(l)==1){
    printf("ERRO: Lista Vazia\n");
    return;
  }

  while(temp!=NULL){
    if (temp->coluna == colunaV && temp->linha == linhaV){
      temp2 = temp2->anterior;
      temp2->proximo = temp->proximo;
      temp2 = temp->proximo;
      temp2->anterior = temp->anterior;
      entrou = 1;
      l->cont--;
      break;
    }
    temp = temp->anterior;
  }

  if(entrou != 1){
    printf("ERRO: coordenada não encontrada\n");
    return;
  }
  return &temp;
}

void imprimeLista(ListaD *l){
  node *temp;
  temp = l->topo;
  while(temp!=NULL){
    printf("(%.2lf,%.2lf) ", temp->linha, temp->coluna);
    temp = temp->anterior;
  }
  printf("\n");
}

void testaObjeto(ListaD *l){
  float a, b, c, d, Cord[20][2];
  int i=0, j=0;
  node *temp;
  temp = l->topo;

  if (l->cont == 3){
    while(temp!=NULL){
      Cord[i][0] = temp->linha;
      Cord[i][1] = temp->coluna;
      //printf("(%.2lf,%.2lf)\n",Cord[i][0], Cord[i][1]);
      temp = temp->anterior;
      i++;
    }
    a = sqrt(((pow((abs(Cord[0][0] - Cord[1][0])),2))+(pow((abs(Cord[0][1] - Cord[1][1])),2))));
    printf("%.2lf ", a);
    j++;
    b = sqrt(((pow((abs(Cord[0][0] - Cord[2][0])),2))+(pow((abs(Cord[0][1] - Cord[2][1])),2))));
    printf("%.2lf ", b);
    j++;
    c = sqrt(((pow((abs(Cord[1][0] - Cord[2][0])),2))+(pow((abs(Cord[1][1] - Cord[2][1])),2))));
    printf("%.2lf\n", c);

    if (Cord[0][0] == Cord [1][0] || Cord[0][0] == Cord[2][0]){
      printf("COORDENADAS COOPLANARES, NÃO FORMA UM TRIÂNGULO\n");
      return;
    } else if (pow(sqrt(((pow((abs(Cord[0][0] - Cord[1][0])),2))+(pow((abs(Cord[0][1] - Cord[1][1])),2)))),2) == sqrt((pow(sqrt(((pow((abs(Cord[0][0] - Cord[2][0])),2))+(pow((abs(Cord[0][1] - Cord[2][1])),2)))),2)+pow(sqrt(((pow((abs(Cord[1][0] - Cord[2][0])),2))+(pow((abs(Cord[1][1] - Cord[2][1])),2)))),2)))){
      printf("TRIANGULO RETANGULO\n");
    }else if (pow(sqrt(((pow((abs(Cord[0][0] - Cord[1][0])),2))+(pow((abs(Cord[0][1] - Cord[1][1])),2)))),2) > sqrt((pow(sqrt(((pow((abs(Cord[0][0] - Cord[2][0])),2))+(pow((abs(Cord[0][1] - Cord[2][1])),2)))),2)+pow(sqrt(((pow((abs(Cord[1][0] - Cord[2][0])),2))+(pow((abs(Cord[1][1] - Cord[2][1])),2)))),2)))){
      printf("TRIANGULO OBTUSANGULO\n");
    }else{
      printf("TRIANGULO ACUTANGULO\n");
    }

    if (a == b == c){
      printf("TRIANGULO EQUILATERO\n");
    }else if (a != b != c){
      printf("TRIANGULO ESCALENO\n");
    }else {
      printf("TRIANGULO ISOSCELES\n");
    }

  } else{
    while(temp!=NULL){
      Cord[i][0] = temp->linha;
      Cord[i][1] = temp->coluna;
      //printf("(%.2lf,%.2lf)\n",Cord[i][0], Cord[i][1]);
      temp = temp->anterior;
      i++;
    }

    a = sqrt(((pow((abs(Cord[0][0] - Cord[1][0])),2))+(pow((abs(Cord[0][1] - Cord[1][1])),2))));
    printf("%.2lf ", a);
    j++;
    b = sqrt(((pow((abs(Cord[0][0] - Cord[3][0])),2))+(pow((abs(Cord[0][1] - Cord[3][1])),2))));
    printf("%.2lf ", b);
    j++;
    c = sqrt(((pow((abs(Cord[3][0] - Cord[2][0])),2))+(pow((abs(Cord[3][1] - Cord[2][1])),2))));
    printf("%.2lf\n", c);
    j++;
    d = sqrt(((pow((abs(Cord[2][0] - Cord[1][0])),2))+(pow((abs(Cord[2][1] - Cord[1][1])),2))));
    printf("%.2lf\n", c);

    if (Cord[0][0] == Cord [1][0] || Cord[0][0] == Cord[2][0] || Cord[0][0] == Cord[3][0]){
      printf("COORDENADAS COOPLANARES, NÃO FORMA UM PARALELOGRAMO\n");
      return;
    } else if ((a == c == b == d) && (Cord[0][0] == Cord[1][0]) && (Cord[3][0] == Cord[2][0]) && (Cord[0][1] == Cord[3][1]) && (Cord[2][1] == Cord[1][1])){
      printf("PARALELOGRAMO QUADRADO\n");
    } else if ((a == c && b == d) && (a < b || a > b) && (Cord[0][0] == Cord[1][0]) && (Cord[3][0] == Cord[2][0]) && (Cord[0][1] == Cord[3][1]) && (Cord[2][1] == Cord[1][1])){
      printf("PARALELOGRAMO RETANGULO\n");
    } else {
      printf("PARALELOGRAMO QUALQUER\n");
    }
  }
}

void converteObjeto(ListaD *l){
  node *temp;
  node *temp2;
  temp = l->topo;
  temp2 = l->topo;

  if (l->cont == 3){
    inserirElemento(&l, 1, 1);
  } else{
    temp2 = temp2->anterior;
    temp2->proximo = temp->proximo;
    temp2 = temp->proximo;
    temp2->anterior = temp->anterior;
  }
}
