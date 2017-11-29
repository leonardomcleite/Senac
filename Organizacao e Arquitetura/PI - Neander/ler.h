#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para utilizar a função de comparar strings.

// Função Ler arquivo
// Parametros:
// Um file.txt
// Matriz de caracteres até o 4° caractere

int ler_arquivo(FILE *arquivotxt, char MatrizI[][4], int Vetor[], char Stexto[], int *EndMem)
{
  int i = 0, j = 0; // Variaveis de auxilio
  char temp[10], temp1[2], temp2[2], temp3[2], temp4[2], texto[1];

  strcpy(temp1, "0");// Inicializando variaveis
  strcpy(temp2, "0");// Inicializando variaveis
  strcpy(temp3, "0");// Inicializando variaveis
  strcpy(temp4, "0");// Inicializando variaveis

  arquivotxt = fopen("tabela.txt", "r"); // Abrindo o arquivo e verificando se ele foi aberto corretamente.
  if (!arquivotxt){
    printf("Falha na abertura do arquivo\n");
    return 1; // O programa para.
  }

  while (!feof(arquivotxt)) // Lendo o arquivo até o final
  {
    if (i > 256){ // Caso tenha mais de 256 linhas
      printf("ERRO: Este micro, dispoe de 256 posicoes de memoria, contudo eh impossivel continuar...!\n");
      return 1; // O programa para.
    }

    fgets(Stexto, 10, arquivotxt); //(String, tamanho, arquivo.txt)

    MatrizI[i][0] = Stexto[0]; // Cada linha "i", vai possuir 4 caractares.
    MatrizI[i][1] = Stexto[1]; // Cada linha "i", vai possuir 4 caractares.
    MatrizI[i][2] = Stexto[2]; // Cada linha "i", vai possuir 4 caractares.
    MatrizI[i][3] = '\0'; // Cada linha "i", vai possuir 4 caractares.

    temp4[0] = Stexto[2];

    if (!strcmp(temp4, " "))
      j=3;
    else
      j=4;

    temp1[0] = Stexto[j];
    temp2[0] = Stexto[j+1];
    temp3[0] = Stexto[j+2];

    strcpy(temp, temp1); // Realizando a cópia do conteúdo de uma variável a outra. 
    strcat(temp, temp2); // Realizando a cópia do conteúdo de uma variável a outra.
    strcat(temp, temp3); // Realizando a cópia do conteúdo de uma variável a outra.

    Vetor[i] = atoi (temp); // Converte temp de String para Int.

    i++;
  }

  *EndMem = i;

  fclose(arquivotxt); // Fecha o arquivo.txt
  return 0;
}
