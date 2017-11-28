#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ler_arquivo(FILE *arquivotxt, char MatrizI[][4], int Vetor[], char Stexto[], int *EndMem)
{
  int i = 0, j = 0;
  char temp[10], temp1[2], temp2[2], temp3[2], temp4[2], texto[1];

  strcpy(temp1, "0");
  strcpy(temp2, "0");
  strcpy(temp3, "0");
  strcpy(temp4, "0");

  arquivotxt = fopen("tabela.txt", "r");
  if (!arquivotxt){
    printf("Falha na abertura do arquivo\n");

    return 1;
  }

  while (!feof(arquivotxt))
  {
    if (i > 256){
      printf("ERRO: Este micro, dispõe de 256 posições de memória, contudo é impossivel continuar...!\n");
      return 1;
    }

    fgets(Stexto, 10, arquivotxt);

    MatrizI[i][0] = Stexto[0];
    MatrizI[i][1] = Stexto[1];
    MatrizI[i][2] = Stexto[2];
    MatrizI[i][3] = '\0';

    temp4[0] = Stexto[2];

    if (!strcmp(temp4, " "))
      j=3;
    else
      j=4;

    temp1[0] = Stexto[j];
    temp2[0] = Stexto[j+1];
    temp3[0] = Stexto[j+2];

    strcpy(temp, temp1);
    strcat(temp, temp2);
    strcat(temp, temp3);

    Vetor[i] = atoi (temp);

    i++;
  }

  *EndMem = i;

  fclose(arquivotxt);
  return 0;
}
