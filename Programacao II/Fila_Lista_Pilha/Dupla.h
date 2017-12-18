#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAMANHO 25

void inicializaObterNumero(){//inicializa o gerador de numeros randomicos
  srand(time(NULL));
}

double obterNumero(){//gera numeros randomicos entre 0 e 1
  int temp;
  temp=rand();
  return temp*1.0/RAND_MAX;
}

void preencheVetor(int *vetor){
  double temp;
  //inicializa o gerador de numeros aleatórios
  inicializaObterNumero();
  for(int i=0;i<TAMANHO;i++){
    temp=100*obterNumero();
    vetor[i]=(int)temp;
  }
}

void criaVetor(int *vetor){
  vetor=(int*)malloc(TAMANHO*sizeof(int));
}

void imprimeVetor(int *vetor){
  for(int i=0; i<TAMANHO; i++){
    printf("%d \n",vetor[i]);
  }
}

int contaMaiores(int *vetor, int chave){
  int contador=0;
  for(int i=0; i<TAMANHO; i++){
    if(vetor[i]>chave){
      contador++;
    }
  }
  return contador;
}

void verificaSoma(int *vetor, int chave){
   for(int i=0; i<TAMANHO-1; i++){
      for(int j=i+1; j<TAMANHO; j++){
        if((vetor[i]+vetor[j])==chave){
            printf("Na posição %d e %d a soma dos valores %d e %d é igual a chave %d\n",i, j, vetor[i], vetor[j], chave);
        }
      }
    }  
}

int main(){
  int *vetor;
  int chave;
  
  criaVetor(&vetor);
  //preenche o vetor com valores entre 0 e 100 e imprime o vetor
  preencheVetor(&vetor);
  imprimeVetor(&vetor);
  //solicita o valor da chave de busca
  printf("Entre com a chave de busca:\n");
  scanf("%d", &chave);
  printf("voce entrou com: %d\n", chave);
  //verifica quantos valores no vetor são maiores que a chave de busca
  printf("Existem %d valores maiores que %d no vetor.\n",contaMaiores(&vetor, chave), chave);
  //verifica se existe algum par de valores no vetor cuja soma seja igual a chave de busca.
  verificaSoma(&vetor, chave);
  
  return 1;
}