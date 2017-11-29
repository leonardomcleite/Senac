#include <stdio.h>
#include <stdlib.h>
#include "infor.h"
#include "simu.h"
#include "ler.h"

int main (void)
{
  FILE *arquivotxt;
  char MatrizI[256][4], Stexto[9];
  int Vetor[256], RI = 0, PC = 0, AC = 0, retorno = 0, EndMem = 0;

  informacoes();

  printf("Pressione qualquer tecla para iniciar a simulacao...\n");
  getc(stdin); // esvazia o buffer e continua sem esperar

  retorno = ler_arquivo(&arquivotxt, &MatrizI, &Vetor, &Stexto, &EndMem);

  if (retorno == 1){
    return 0;
  }
  while (simulador(&MatrizI, &Vetor, &RI, &PC, &AC, &EndMem) != 1) {
    printf("Pressione qualquer tecla para iniciar a simulacao...\n");
    getc(stdin); // esvazia o buffer e continua sem esperar
  }
}
