#include <stdio.h>
#include <ctype.h> // Necessário para isdigit
#include <string.h> // Necessário para strcpy e strcat
#include <stdlib.h>

FILE *arquivotxt;

int abre_arquivo ();
int ler_arquivo();
int busca_binaria ();

//======================================================================================
//# PRINCIPAL
//======================================================================================

int main (void)
{
  char Matriz[9999][3], texto[9999];
  int cont = 0, k = 0;
  
  // Função pra abrir o arquivo texto
  abre_arquivo();
  
  // função para ler o arquivo
  k = ler_arquivo(Matriz, texto);
  
  // Função para realizar a contagem de empresas
  cont = busca_binaria (k, Matriz);

  printf ("Foram contabilizadas %d empresas aéreas.\n", cont);
}

//======================================================================================
//# FUNÇÕES
//======================================================================================

int abre_arquivo (void)
{
  // Abre um arquivo
  arquivotxt = fopen("Tabela.txt", "r");
  
  if (arquivotxt == NULL)  // Verifica se houve erro na abertura
  {
    printf("Falha na abertura do arquivo\n");
    return 0;
  }
  return 1;
}

//======================================================================================

int ler_arquivo (char Matriz[][3], char texto[])
{
  int i = 0;
  
  while (!feof(arquivotxt)) // Enquanto houver linhas preenchidas no arquivo
  {
    fgets(texto, 9999, arquivotxt); //string de uma linha inteira
    Matriz[i][0] = texto [0];
    Matriz[i][1] = texto [1];
    Matriz[i][2] = texto [2];
    i++;
  }
  fclose(arquivotxt); //Fecha o arquivo
  return i;
}

//======================================================================================

int busca_binaria (int j, char Matriz[][3])
{
  int pivot=0, ultimo=0, ult = 0, contagem=0, comparador=0, base=0, sair=0;
  
  pivot = 0;
  base= 1;
  ultimo = j-1;
  comparador = ultimo;
  ult=ultimo-1;

  //printf("%d %d %d %d %d %d\n", base, comparador, pivot, ultimo, ult, contagem);
  
  while(comparador >= base)
  {
    if((Matriz[pivot][0] != Matriz[comparador][0] || Matriz[pivot][1] != Matriz[comparador][1] || Matriz[pivot][2] != Matriz[comparador][2]) && comparador != base)
    {
      while(sair==0)
      {
        if (Matriz[ult][0] == Matriz[ultimo][0] && Matriz[ult][1] == Matriz[ultimo][1] && Matriz[ult][2] == Matriz[ultimo][2])
        {
          ultimo--;
          ult = ultimo-1;
          //printf("*%d %d %d %d %d %d\n",base, comparador, pivot, ultimo, ult, contagem);
        }else
        {
          break;
        }
      }
      ult--;
      ultimo--;
      contagem++;
      comparador = base;
      //printf("#%d %d %d %d %d %d\n",base, comparador, pivot, ultimo, ult, contagem);
    }else if((Matriz[pivot][0] == Matriz[comparador][0] || Matriz[pivot][1] == Matriz[comparador][1] || Matriz[pivot][2] == Matriz[comparador][2]) && comparador == ultimo)
    {
      break;
    }else 
    {
      if ((Matriz[pivot][0] != Matriz[comparador][0] || Matriz[pivot][1] != Matriz[comparador][1] || Matriz[pivot][2] != Matriz[comparador][2]) && comparador == base)
      {
        pivot = base;
        base++;
        comparador = ultimo;
        if (comparador == base && comparador == ultimo)
        {
          contagem = contagem + 2;
        }else
        {
        contagem++;
        }
        //printf("&%d %d %d %d %d %d\n",base, comparador, pivot, ultimo, ult, contagem);
      }else
      {
        base++;
        comparador = base;
        //printf("$%d %d %d %d %d %d\n",base, comparador, pivot, ultimo, ult, contagem);
      }
    }
  }
  contagem++;
  return contagem;
}
