#include <stdio.h>
#include <stdlib.h>
#include "infor.h"
#include "simu.h"
#include "ler.h"

int main (void)
{
  FILE *arquivotxt; // Arquivo.txt
  char MatrizI[256][4], Stexto[9]; // Matriz de até 256 linhas e 4 colunas(4 caracteres)
  int Vetor[256], RI = 0, PC = 1, AC = 0, JN = 0 , JZ = 0, retorno = 0, EndMem = 0; //Vetor de até 256 linhas - Regitrador de Instrução - PC - Acumulador

  informacoes();

  printf("Pressione qualquer tecla para iniciar a simulacao...\n");
  getc(stdin); // esvazia o buffer e continua sem esperar

  retorno = ler_arquivo(&arquivotxt, &MatrizI, &Vetor, &Stexto, &EndMem);

  if (retorno == 1){ // Caso a "Memória" fiquei com um número maior que 256 posições.
    return 0; // O programa para.
  }
  while (simulador(&MatrizI, &Vetor, &RI, &PC, &AC, &EndMem, &JN, &JZ) != 1) {
    printf("\nPressione qualquer tecla para continuar a simulacao...\n");
    getc(stdin); // esvazia o buffer e continua sem esperar
  }
}
