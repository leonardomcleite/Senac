#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simulador(char MatrizI[][4], int Vetor[], int *RI, int *PC, int *AC, int *EndMem)
{
  if (!strcmp(MatrizI[*PC],"NOP") || !strcmp(MatrizI[*PC],"STA") || !strcmp(MatrizI[*PC],"LDA")||
  !strcmp(MatrizI[*PC],"ADD")|| !strcmp(MatrizI[*PC],"OR ")|| !strcmp(MatrizI[*PC],"AND")||
  !strcmp(MatrizI[*PC],"NOT") || !strcmp(MatrizI[*PC],"JMP") || !strcmp(MatrizI[*PC],"HLT") ||
  (Vetor[*PC] >= -127 & Vetor[*PC] <= 128))
  {
    if (!strcmp(MatrizI[*PC] , "HLT"))
    {
      printf("\nFIM DA SIMULAÇÃO COM A INSTRUÇÃO HALT\n");
      printf("PC = %d\n", *PC);
      printf("AC = %d\n", *AC);
      printf("MEMÓRIA UTILIZADA = %d Endereços\n", *EndMem);
      return 1;
    } else if (!strcmp(MatrizI[*PC] , "NOP"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("• A CPU enviou o conteúdo do PC (%d) que no caso é endereço da próxima instrução via BE, para o REM.\n", *PC);
      printf("• A MP lê o REM e retorna para o RDM o conteúdo deste endereço via BD. Logo depois o dado (%s %d) é transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("• O RI passa a instrução para o UC.\n");
      printf("• A UC decodifica a instrução.\n");
      printf("• Como se trata de NOP, nada é executado.\n");
      *PC += 1;
      printf("• Por fim o PC é incrementado:Logo PC = %d", *PC);
    } else if (!strcmp(MatrizI[*PC] , "STA"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      MatrizI[Vetor[*PC]][0] = *AC;
      printf("• A CPU enviou o conteúdo do PC (%d) que no caso é endereço da próxima instrução via BE, para o REM.\n", *PC);
      printf("• A MP lê o REM e retorna para o RDM o conteúdo deste endereço via BD. Logo depois o dado (%s %d) é transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("• O RI passa a instrução para o UC.\n");
      printf("• A UC decodifica a instrução.\n");
      printf("• Como se trata de STA (Armazena AC), a MP recebe um comando de gravação onde são passados endereço (%d) e dado (%d) a ser gravado, que no caso é o dado do AC.\n", Vetor[*PC], *AC);
      *PC += 1;
      printf("• Por fim o PC é incrementado: Logo PC = %d", *PC);
      if (*EndMem < Vetor[*PC]){
        *EndMem += 1;
      }
    }else if (!strcmp(MatrizI[*PC] , "LDA"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC = atoi (MatrizI[Vetor[*PC]]);
      printf("• A CPU enviou o conteúdo do PC (%d) que no caso é endereço da próxima instrução via BE, para o REM.\n", *PC);
      printf("• A MP lê o REM e retorna para o RDM o conteúdo deste endereço via BD. Logo depois o dado (%s %d) é transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("• O RI passa a instrução para o UC.\n");
      printf("• A UC decodifica a instrução.\n");
      printf("• Como se trata de LDA (Carrega AC), a UC passa para ULA a realização da operação IGUAL:\n");
      printf("  - É realizada uma busca na MP no endereço (%d), retornado o dado (%d)\n", Vetor[*PC], atoi (MatrizI[Vetor[*PC]]));
      printf("  - O resultado (%d) desta operação é enviado para o AC.\n", *AC);
      if (*AC < 0){
        printf("  - Como o resultado (%d) desta operação é negativo a flag N é ativada.\n", *AC);
        
      }else {
        printf("  - Como o resultado (%d) desta operação é positivo a flag Z é ativada.\n", *AC);
      }
      *PC += 1;
      printf("• Por fim o PC é incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "ADD"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC += atoi (MatrizI[Vetor[*PC]]);
      printf("• A CPU enviou o conteúdo do PC (%d) que no caso é endereço da próxima instrução via BE, para o REM.\n", *PC);
      printf("• A MP lê o REM e retorna para o RDM o conteúdo deste endereço via BD. Logo depois o dado (%s %d) é transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("• O RI passa a instrução para o UC.\n");
      printf("• A UC decodifica a instrução.\n");
      printf("• Como se trata de ADD (Soma ao AC), a UC passa para ULA a realização da operação SOMA:\n");
      printf("  - Esta recebe o dado do AC, e logo após é realizada uma busca na MP no endereço (%d), retornado o dado (%d), e somado-o ao dado do AC;\n", Vetor[*PC], MatrizI[*PC]);
      printf("  - O resultado (%d) desta operação é enviado para o AC.\n", *AC);
      if (*AC < 0)
        printf("  - Como o resultado (%d) desta operação é negativo a flag N é ativada.\n", *AC);
      else
        printf("  - Como o resultado (%d) desta operação é positivo a flag Z é ativada.\n", *AC);

      *PC += 1;
      printf("• Por fim o PC é incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "OR "))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *PC += 1;
      printf("• Incrementa o PC: ");
      printf("PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "AND"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("• Compara AC com Valor da Memoria no Endereço: %d\n", Vetor[*PC]);
      if (MatrizI[Vetor[*PC]][0] == *AC)
      {
        printf("  - AC igual ao Valor da Memória no Endereço %d\n", Vetor[*PC]);
        *PC = 5;
        printf("•Incrementa o PC: ");
        printf("PC = %d", *PC);
      }else
      {
        printf("  - AC diferente ao Valor da Memória no Endereço %d\n", Vetor[*PC]);
        *PC += 1;
        printf("•Incrementa o PC: ");
        printf("PC = %d", *PC);
      }
    }else if(!strcmp(MatrizI[*PC] , "NOT"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *PC += 1;
      printf("• Incrementa o PC: ");
      printf("• PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "JMP"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("• Pula para instrução da linha de comandos %d.\n", Vetor[*PC]);
      *PC = Vetor[*PC];
      printf("PC = %d", *PC);
    }
    printf("\n");
  } else
  {
    if (Vetor[*PC] < -127 & Vetor[*PC] > 128)
    {
      printf("ERRO: Este micro, só pode realizar contas com números > -126 e < 129\n");
    } else {
      printf("ERRO: Fim das instruções, sem sererem finalizadas com HALT\n");
    }
    return 1;
  }
  return 0;
}
