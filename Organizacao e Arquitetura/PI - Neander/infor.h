#include <stdio.h>
#include <stdlib.h>

void informacoes()
{
  printf("=================================================================\n");
  printf("INFORMAÇÕES\n");
  printf("=================================================================\n");

  printf("\nSIMULADOR NEANDER \n\n");

  printf("GRANDE OBSERVAÇÃO:\n#QUANDO FOR ENDEREÇAR A MEMÓRIA LEMBRE-SE DE QUE NO EDITOR DE TEXTO AS LINHAS COMEÇAM DO NÚMERO '1' E PARA O NOSSO SIMULADOR É '0'#\n\n\n");

  printf("ARQUITETURA\n");
  printf("• Largura de dados (BD), endereços (BE) de 8 bits\n");
  printf("• Dados representados em complemento de 2 (-127 à 128)\n");
  printf("• 1 acumulador de 8 bits (AC)\n");
  printf("• 1 apontador de programa de 8 bits (PC)\n");
  printf("• 1 registrador de instruções de 8 bits (RI)\n");
  printf("• 1 registrador de endereços de 8 bits (REM)\n");
  printf("• 1 registrador de dados de 8 bits (RDM)\n");
  printf("• 1 registrador de estado com 2 códigos de condição: \n negativo (N) e zero (Z)\n");
  printf("• 1 modo de endereçamento: end. direto a memória\n\n");

  printf("----------------------------------------------\n");
  printf("| Código | Instrução |      Comentário       |\n");
  printf("----------------------------------------------\n");
  printf("|  0000  | NOP       | Nenhuma operação      |\n");
  printf("|  0001  | STA end   | MEM(end) <- AC        |\n");
  printf("|  0010  | LDA end   | AC <- MEM(end)        |\n");
  printf("|  0011  | ADD end   | AC <- MEM(end) + AC   |\n");
  printf("|  0100  | OR end    | AC <- MEM(end) OR AC  |\n");
  printf("|  0101  | AND end   | AC <- MEM(end) AND AC |\n");
  printf("|  0110  | NOT       | AC <- NOT AC          |\n");
  printf("|  1000  | JMP end   | PC <- end             |\n");
  printf("|  1001  | JN end    | IF N=1 THEN PC <- end |\n");
  printf("|  1010  | JZ end    | IF Z=1 THEN PC <- end |\n");
  printf("|  1111  | HLT       | Pára processamento    |\n");
  printf("----------------------------------------------\n");

  printf("\nORGANIZAÇÃO\n");
  printf("• Um registrador de 8 bits para servir de acumulador\n");
  printf("• Um registrador de 8 bits para o PC (registrador-contador)\n");
  printf("• Dois flip-flops: um para o código de condição N e outro para Z\n");
  printf("• Uma memória (MP) de 256 posições (endereços) x 8 bits\n");


  printf("\n=================================================================\n");
  printf("SIMULADOR\n");
  printf("=================================================================\n\n");

}
