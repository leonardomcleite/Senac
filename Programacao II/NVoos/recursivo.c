#include <stdio.h>
#include <string.h>

FILE *arquivotxt;

int abre_arquivo ();
int ler_arquivo();
int contagemBinaria ();

int main()
{
  char Matriz[3000][4], texto[3000];
  int cont = 0, k = 0, i = 0;
  
  // Abre um arquivo
  arquivotxt = fopen("Tabela.txt", "r");
  
  if (arquivotxt == NULL)  // Verifica se houve erro na abertura
  {
    printf("Falha na abertura do arquivo\n");
    return 0;
  }
  
  while (!feof(arquivotxt)) // Enquanto houver linhas preenchidas no arquivo
  {
    fgets(texto, 3000, arquivotxt); //string de uma linha inteira
    Matriz[i][0] = texto [0];
    Matriz[i][1] = texto [1];
    Matriz[i][2] = texto [2];
    Matriz[i][3] = '\0';
    i++;
  }
  fclose(arquivotxt); //Fecha o arquivo
  i--;

  printf("Foram contabilizadas %d empresas aéreas\n",busca_binaria(Matriz, 0, i, "") + 1);
}

//======================================================================================
//# FUNÇÕES
//======================================================================================

int busca_binaria(char MatrizC[][4], int inicio, int fim, char meioa[])
{
  int meio = (inicio + fim)/2;
  int contagem = 0;
  
  if((inicio>=fim)||(!strcmp(MatrizC[inicio],MatrizC[fim])))
  {
    return 0;
  }

  if(strcmp(MatrizC[inicio],MatrizC[meio]))
  {
      if(strcmp(MatrizC[inicio],meioa)&&strcmp(MatrizC[meio],meioa))
      {
        contagem++;
      }
      contagem += busca_binaria(MatrizC,inicio,meio-1,MatrizC[meio]);
  }

  if(strcmp(MatrizC[meio],MatrizC[fim]))
  {
      if(strcmp(MatrizC[fim],meioa)&&strcmp(MatrizC[meio],meioa))
      {
        contagem++;
      }
      contagem += busca_binaria(MatrizC,meio+1,fim,MatrizC[meio]);
  }
  return contagem;
}