#include <stdio.h>
#include <ctype.h> // Necessário para isdigit
#include <string.h> // Necessário para strcpy e strcat
#include <stdlib.h>

#define LIN 9999
#define COL 61
#define H 15 // 1º Caracter de inicio da 1º dezena
#define G 16 // 2º Caracter de inicio da 1º dezena


FILE* abrir_arquivo()
{

  FILE *arquivotxt;  
  
  // Abre um arquivo
  arquivotxt = fopen("Tabela.txt", "r");
  
  if (arquivotxt == NULL)  // Verifica se houve erro na abertura
  {
    printf("Falha na abertura do arquivo\n");
    return 0;
  }
  return arquivotxt;  
}

int ler_arquivo(int *Matriz, FILE* arquivotxt)
{
  char valor[10], texto[LIN], carc1[2], carc2[2];
  int g=G, h=H, c=0, k=-1, n=0, valor2;


  while (!feof(arquivotxt)) // Enquanto houver linhas preenchidas no arquivo
  {
    
    fgets(texto, LIN, arquivotxt); //string de uma linha inteira
  
    if(isdigit(texto[0]) && strlen(texto)>115){ // Verifica se valor informado é carac

      k++;
      *(Matriz+(COL*k))=k+1; //Concurso
      
      c=0;
      n=k+1;
      if(n>=10) //Saber quantos digitos tem o k
      {
        for(c=1; n; n/=10) // O n/=10 significa pegar o resultado e dividir por 10
          c++;

        c=c-2;
      }
      printf("Concurso: %d - ", k+1);

      for (int a=0; a<6; a++)
      {        

        carc1[0]=texto[h+c];
        carc2[0]=texto[g+c];

        g=g+4;
        h=h+4;
        
        strcpy(valor,carc1);
        strcat(valor,carc2);
        
        valor2=atoi(valor);

        printf("%02d ", valor2);
        
        *(Matriz+(COL*k+valor2))=valor2; // Dezenas
      }
      printf("\n");
    }
    h=H;
    g=G;
  }
  fclose(arquivotxt); //Fecha o arquivo
  return k;  
}

void verifica_mais_sorteado(int *Matriz, int l, int *MatrizOrd)
{
  int valor=0, Aux=0, Aux2=0, cont=0, j=0, s=0, Colunas=2;

  for (j=1;j<COL;j++) // Carrega o MatrizOrd via vetor
  {
    for (s=0;s<=l;s++)
    {
      if (*(Matriz+(COL*s+j))==j)
      {
        cont++;
      } 
    }
    *(MatrizOrd+(Colunas*(j-1)))=j;
    *(MatrizOrd+(Colunas*(j-1)+1))=cont; 
    cont=0;
  }  

  for (int v=0;v<COL;v++) // Ordena a MatrizOrd em ordem crescente
  {
    for (int s=0;s<COL-2;s++)
    {
      if (*(MatrizOrd+(Colunas*s+1))>*(MatrizOrd+(Colunas*(s+1)+1)))
      {
        Aux=*(MatrizOrd+(Colunas*s));
        Aux2=*(MatrizOrd+(Colunas*s+1));
        
        *(MatrizOrd+(Colunas*s))=*(MatrizOrd+(Colunas*(s+1)));
        *(MatrizOrd+(Colunas*s+1))=*(MatrizOrd+(Colunas*(s+1)+1));
        *(MatrizOrd+(Colunas*(s+1)))=Aux;
        *(MatrizOrd+(Colunas*(s+1)+1))=Aux2;
      }     
    }
  }

}

int main ()
{
  int Matriz[LIN][COL], MatrizOrd[LIN][2], Sequencia[6], k=0, i=0, m=0;
  FILE *arquivotxt;
  
  arquivotxt=abrir_arquivo();

  k=ler_arquivo(&Matriz[0][0],arquivotxt);

  verifica_mais_sorteado(&Matriz[0][0], k, &MatrizOrd[0][0]);

  // +++++++++++++++++++++ Resoluções do problema +++++++++++++++++++ //

  printf("\nE1 - As 6 dezenas mais sorteadas foram: ");
  for (i=COL-2;i>53;i--)  
    printf("%d ",MatrizOrd[i][0]);

  printf("\n\nE2 - As 6 dezenas menos sorteadas foram: ");
  for (i=0;i<6;i++)   
    printf("%d ",MatrizOrd[i][0]);

  printf("\n\nE3 - Digite 6 dezenas para verificar se ja foram sorteadas: ");
  for (i=0;i<6;i++)
    scanf("%d",&Sequencia[i]);

  for (i=0;i<=k;i++)
  {
    for (m=0;m<6;m++)
    {
      if (Matriz[i][Sequencia[m]]!=Sequencia[m])
        break;
    }
    if (m==6)
    {
      printf("\n*Esta sequencia ja foi sorteada! (Concurso Nº%d)*\n",i+1);
      break;
    }
  }
  if (i>k)
  printf("\n*Esta sequencia ainda não foi sorteada!*\n");

  printf("\n");
  
  return 0;
}