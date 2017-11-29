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
      printf("\nFIM DA SIMULACAO COM A INSTRUCAO HALT\n");
      printf("PC = %d\n", *PC);
      printf("AC = %d\n", *AC);
      printf("MEMORIA UTILIZADA = %d Enderecos\n", *EndMem);
      return 1;
    } else if (!strcmp(MatrizI[*PC] , "NOP"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de NOP, nada eh executado.\n");
      *PC += 1;
      printf("- Por fim o PC eh incrementado: Logo PC = %d", *PC);
    } else if (!strcmp(MatrizI[*PC] , "STA"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      MatrizI[Vetor[*PC]][0] = *AC;
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de STA (Armazena AC), a MP recebe um comando de gravacao onde sao passados endereco (%d) e dado (%d) a ser gravado, que no caso eh o dado do AC.\n", Vetor[*PC], *AC);
      *PC += 1;
      printf("- Por fim o PC eh incrementado: Logo PC = %d", *PC);
      if (*EndMem < Vetor[*PC]){
        *EndMem += 1;
      }
    }else if (!strcmp(MatrizI[*PC] , "LDA"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC = atoi (MatrizI[Vetor[*PC]]);
      printf("- A CPU enviou o conteúdo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de LDA (Carrega AC), a UC passa para ULA a realizacao da operacao IGUAL:\n");
      printf("  - Eh realizada uma busca na MP no endereco (%d), retornado o dado (%d)\n", Vetor[*PC], atoi (MatrizI[Vetor[*PC]]));
      printf("  - O resultado (%d) desta operacao eh enviado para o AC.\n", *AC);
      if (*AC < 0){
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag N eh ativada.\n", *AC);

      }else {
        printf("  - Como o resultado (%d) desta operacao eh positivo a flag Z eh ativada.\n", *AC);
      }
      *PC += 1;
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "ADD"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC += atoi (MatrizI[Vetor[*PC]]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de ADD (Soma ao AC), a UC passa para ULA a realizacao da operacao SOMA:\n");
      printf("  - Esta recebe o dado do AC, e logo apos eh realizada uma busca na MP no endereco (%d), retornado o dado (%d), e somado-o ao dado do AC;\n", Vetor[*PC], MatrizI[*PC]);
      printf("  - O resultado (%d) desta operacao eh enviado para o AC.\n", *AC);
      if (*AC < 0)
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag N eh ativada.\n", *AC);
      else
        printf("  - Como o resultado (%d) desta operacao eh positivo a flag Z eh ativada.\n", *AC);

      *PC += 1;
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "OR "))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *PC += 1;
      printf("- Incrementa o PC: ");
      printf("PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "AND"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- Compara AC com Valor da Memoria no Endereco: %d\n", Vetor[*PC]);
      if (MatrizI[Vetor[*PC]][0] == *AC)
      {
        printf("  - AC igual ao Valor da Memoria no Endereco %d\n", Vetor[*PC]);
        *PC = 5;
        printf("-Incrementa o PC: ");
        printf("PC = %d", *PC);
      }else
      {
        printf("  - AC diferente ao Valor da Memoria no Endereco %d\n", Vetor[*PC]);
        *PC += 1;
        printf("-Incrementa o PC: ");
        printf("PC = %d", *PC);
      }
    }else if(!strcmp(MatrizI[*PC] , "NOT"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *PC += 1;
      printf("- Incrementa o PC: ");
      printf("- PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "JMP"))
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- Pula para instrucao da linha de comandos %d.\n", Vetor[*PC]);
      *PC = Vetor[*PC];
      printf("PC = %d", *PC);
    }
    printf("\n");
  } else
  {
    if (Vetor[*PC] < -127 & Vetor[*PC] > 128)
    {
      printf("ERRO: Este micro, so pode realizar contas com numeros > -126 e < 129\n");
    } else {
      printf("ERRO: Fim das instrucaes, sem sererem finalizadas com HALT\n");
    }
    return 1;
  }
  return 0;
}
