#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simulador(char MatrizI[][4], int Vetor[], int *RI, int *PC, int *AC, int *EndMem, int *JN, int *JZ)
{
  if (!strcmp(MatrizI[*PC],"NOP") || !strcmp(MatrizI[*PC],"STA") || !strcmp(MatrizI[*PC],"LDA")||
  !strcmp(MatrizI[*PC],"ADD")|| !strcmp(MatrizI[*PC],"OR ")|| !strcmp(MatrizI[*PC],"AND")||
  !strcmp(MatrizI[*PC],"NOT") || !strcmp(MatrizI[*PC],"JMP") || !strcmp(MatrizI[*PC],"HLT") ||
  (Vetor[*PC] >= -127 & Vetor[*PC] <= 128))
  {
    if (!strcmp(MatrizI[*PC] , "HLT")) //Se a instrução digitada seja HLT
    {
      printf("\nFIM DA SIMULACAO COM A INSTRUCAO HALT\n");
      printf("PC = %d\n", *PC);
      printf("AC = %d\n", *AC);
      printf("MEMORIA UTILIZADA = %d Enderecos\n", *EndMem);
      return 1;
    } else if (!strcmp(MatrizI[*PC] , "NOP")) //Se a instrução digitada seja NOP
      {
        printf("\n%s\n", MatrizI[*PC]);
        printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
        printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s) eh transferido para o RI.\n", MatrizI[*PC]);
        printf("- O RI passa a instrucao para o UC.\n");
        printf("- A UC decodifica a instrucao.\n");
        printf("- Como se trata de NOP, nada eh executado.\n");
        *PC += 1; // Incremento PC
        printf("- Por fim o PC eh incrementado: Logo PC = %d", *PC);

      } else if (!strcmp(MatrizI[*PC] , "STA")) //Se a instrução digitada seja STA
      {
        printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
        MatrizI[Vetor[*PC]][0] = *AC;
        printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
        printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
        printf("- O RI passa a instrucao para o UC.\n");
        printf("- A UC decodifica a instrucao.\n");
        printf("- Como se trata de STA (Armazena AC), a MP recebe um comando de gravacao onde sao passados endereco (%d) e dado (%d) a ser gravado, que no caso eh o dado do AC.\n", Vetor[*PC], *AC);
        *PC += 1; // Incremento PC
        printf("- Por fim o PC eh incrementado: Logo PC = %d", *PC);
      if (*EndMem < Vetor[*PC]){
        *EndMem += 1;
      }
    }else if (!strcmp(MatrizI[*PC] , "LDA")) //Se a instrução digitada seja STA
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC = atoi (MatrizI[Vetor[*PC]]);
      printf("- A CPU enviou o conteúdo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de LDA (Carrega AC), a UC passa para ULA a realizacao da operacao LOGICA:\n");
      printf("  - Eh realizada uma busca na MP no endereco (%d), retornado o dado (%d)\n", Vetor[*PC], atoi (MatrizI[Vetor[*PC]]));
      printf("  - O resultado (%d) desta operacao eh enviado para o AC.\n", *AC);

      printf("AC recebe o resultado da operação, Logo AC = %d\n",*AC);

      if (*AC < 0){ //Acumulador seja negativo
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag JN eh ativada.\n", *AC);
        JN = 1;
      }else if (*AC == 0) {
        printf("  - Como o resultado (%d) desta operacao eh zero a flag JZ eh ativada.\n", *AC);
        JZ = 1;
        JN = 0;
      } else if (*AC > 0) {
        JN = 0;
        JZ = 0;
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);

    }else if(!strcmp(MatrizI[*PC] , "ADD")) //Se a instrução digitada seja ADD
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      *AC += atoi (MatrizI[Vetor[*PC]]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de ADD (Soma ao AC), a UC passa para ULA a realizacao da operacao SOMA:\n");
      printf("  - Esta recebe o dado do AC, e logo apos eh realizada uma busca na MP no endereco (%d), retornado o dado (%d), e somado-o ao dado do AC\n", Vetor[*PC], atoi (MatrizI[Vetor[*PC]]));
      printf("  - O resultado (%d) desta operacao eh enviado para o AC.\n", *AC);

      if (*AC < 0){ //Acumulador seja negativo
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag JN eh ativada.\n", *AC);
        JN = 1;
      }else if (*AC == 0) {
        printf("  - Como o resultado (%d) desta operacao eh zero a flag JZ eh ativada.\n", *AC);
        JZ = 1;
        JN = 0;
      } else if (*AC > 0) {
        JN = 0;
        JZ = 0;
      }
      *PC += 1; // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);

    }else if(!strcmp(MatrizI[*PC] , "OR ")) //Se a instrução digitada seja OR
    {
      int BinAC[8], BinED[8];
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de OR, a UC passa para ULA a realizacao da operacao LOGICA:\n");

      printf("\n  AC = %d\n", *AC);
      printf("  Valor do endereço buscado = %d\n\n",atoi(MatrizI[Vetor[*PC]]));

      Trasnformacao(*AC, &BinAC);
      Trasnformacao(atoi(MatrizI[Vetor[*PC]]), &BinED);

      for(int indice=0;indice<=6;indice++){
        if (BinAC[indice] == 1 || BinED[indice] == 1)
          BinAC[indice] = 1;
        else
          BinAC[indice] = 0;
      }

      printf("  ____________________\n");

      for(int indice=0;indice<=6;indice++)
        printf("  %d", BinAC[indice]);

      printf("\n");

      int temp = 0;

      if (BinAC[0] == 1)
        temp += 1;

      if (BinAC[1] == 1)
        temp += 2;

      if (BinAC[2] == 1)
        temp += 4;

      if (BinAC[3] == 1)
        temp += 8;

      if (BinAC[4] == 1)
        temp += 16;

      if (BinAC[5] == 1)
        temp += 32;

      if (BinAC[6] == 1)
        temp += 64;

      if (BinAC[7] == 1)
        temp += 128;

      *AC = temp;

      printf("AC recebe o resultado da operação, Logo AC = %d\n",*AC);

      if (*AC < 0){ //Acumulador seja negativo
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag JN eh ativada.\n", *AC);
        JN = 1;
      }else if (*AC == 0) {
        printf("  - Como o resultado (%d) desta operacao eh zero a flag JZ eh ativada.\n", *AC);
        JZ = 1;
        JN = 0;
      } else if (*AC > 0) {
        JN = 0;
        JZ = 0;
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);

    }else if(!strcmp(MatrizI[*PC] , "AND")) //Se a instrução digitada seja ADD
    {
      int BinAC[8], BinED[8];
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de AND, a UC passa para ULA a realizacao da operacao LOGICA:\n");

      printf("\n  AC = %d\n", *AC);
      printf("  Valor do endereço buscado = %d\n\n",atoi(MatrizI[Vetor[*PC]]));

      Trasnformacao(*AC, &BinAC);
      Trasnformacao(atoi(MatrizI[Vetor[*PC]]), &BinED);

      for(int indice=0;indice<=6;indice++){
        if (BinAC[indice] == 1 && BinED[indice] == 1)
          BinAC[indice] = 1;
        else
          BinAC[indice] = 0;
      }

      printf("  ____________________\n");

      for(int indice=0;indice<=6;indice++)
        printf("  %d", BinAC[indice]);

      printf("\n");

      int temp = 0;

      if (BinAC[0] == 1)
        temp += 1;

      if (BinAC[1] == 1)
        temp += 2;

      if (BinAC[2] == 1)
        temp += 4;

      if (BinAC[3] == 1)
        temp += 8;

      if (BinAC[4] == 1)
        temp += 16;

      if (BinAC[5] == 1)
        temp += 32;

      if (BinAC[6] == 1)
        temp += 64;

      if (BinAC[7] == 1)
        temp += 128;

      *AC = temp;

      printf("AC recebe o resultado da operação, Logo AC = %d\n",*AC);

      if (*AC < 0){ //Acumulador seja negativo
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag JN eh ativada.\n", *AC);
        JN = 1;
      }else if (*AC == 0) {
        printf("  - Como o resultado (%d) desta operacao eh zero a flag JZ eh ativada.\n", *AC);
        JZ = 1;
        JN = 0;
      } else if (*AC > 0) {
        JN = 0;
        JZ = 0;
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);

    }else if(!strcmp(MatrizI[*PC] , "NOT")) //Se a instrução digitada seja NOT
    {
      int BinAC[8], BinED[8];
      printf("\n%s\n", MatrizI[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s) eh transferido para o RI.\n", MatrizI[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de NOT, a UC passa para ULA a realizacao da operacao LOGICA:\n");

      printf("\n  AC = %d\n", *AC);

      Trasnformacao(*AC, &BinAC);

      for(int indice=0;indice<=6;indice++){
        if (BinAC[indice] == 1)
          BinAC[indice] = 0;
        else
          BinAC[indice] = 1;
      }

      printf("  ____________________\n");

      for(int indice=0;indice<=6;indice++)
        printf("  %d", BinAC[indice]);

      printf("\n");

      int temp = 0;

      if (BinAC[0] == 1)
        temp += 1;

      if (BinAC[1] == 1)
        temp += 2;

      if (BinAC[2] == 1)
        temp += 4;

      if (BinAC[3] == 1)
        temp += 8;

      if (BinAC[4] == 1)
        temp += 16;

      if (BinAC[5] == 1)
        temp += 32;

      if (BinAC[6] == 1)
        temp += 64;

      if (BinAC[7] == 1)
        temp += 128;

      *AC = temp;

      printf("AC recebe o resultado da operação, Logo AC = %d\n",*AC);

      if (*AC < 0){ //Acumulador seja negativo
        printf("  - Como o resultado (%d) desta operacao eh negativo a flag JN eh ativada.\n", *AC);
        JN = 1;
      }else if (*AC == 0) {
        printf("  - Como o resultado (%d) desta operacao eh zero a flag JZ eh ativada.\n", *AC);
        JZ = 1;
        JN = 0;
      } else if (*AC > 0) {
        JN = 0;
        JZ = 0;
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);

    }else if(!strcmp(MatrizI[*PC] , "JMP")) //Se a instrução digitada seja JMP
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de JMP (Pula instrução), a UC passa para ULA a realizacao da operacao SOMA:\n");
      printf("- Pula para instrucao da linha de comandos %d.\n", Vetor[*PC]);
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "JN ")) //Se a instrução digitada seja JMP
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de JN (JUMP Condicional NEGATIVO), a UC verifica se a FLAG JN:\n");

      if (*JN == 1){
        printf("- Como JN esta flegada, o PC recebe o endereço (%d) informado e pula-se para esta instrucao da linha de comandos.\n", Vetor[*PC]);
        *PC = Vetor[*PC];
      } else {
        printf("- Como JN não esta flegada, nada acontece.\n");
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);
    }else if(!strcmp(MatrizI[*PC] , "JZ ")) //Se a instrução digitada seja JMP
    {
      printf("\n%s %d\n", MatrizI[*PC], Vetor[*PC]);
      printf("- A CPU enviou o conteudo do PC (%d) que no caso eh endereco da proxima instrucao via BE, para o REM.\n", *PC);
      printf("- A MP le o REM e retorna para o RDM o conteudo deste endereco via BD. Logo depois o dado (%s %d) eh transferido para o RI.\n", MatrizI[*PC], Vetor[*PC]);
      printf("- O RI passa a instrucao para o UC.\n");
      printf("- A UC decodifica a instrucao.\n");
      printf("- Como se trata de JZ (JUMP Condicional ZERO), a UC verifica a FLAG JZ:\n");

      if (*JZ == 1){
        printf("- Como JZ esta flegada, o PC recebe o endereço (%d) informado e pula-se para esta instrucao da linha de comandos.\n", Vetor[*PC]);
        *PC = Vetor[*PC];
      } else {
        printf("- Como JZ não esta flegada, nada acontece.\n");
      }
      *PC += 1;  // Incremento PC
      printf("- Por fim o PC eh incrementado: PC = %d", *PC);
    }
    printf("\n");
  } else
  {
    if (Vetor[*PC] < -127 & Vetor[*PC] > 128) // Numero de contas
    {
      printf("ERRO: Este micro, so pode realizar contas com numeros > -127 e < 128\n");
    } else {
      printf("ERRO: Fim das instrucaes, sem sererem finalizadas com HALT\n");
    }
    return 1;
  }
  return 0;
}

int Trasnformacao(int decimal, int *binario){

  int indice, resto;

  while( decimal < -127 || decimal > 128 );

    for( indice=0;indice<=6;indice++)
      binario[indice] = 0;

    indice = 6;
    while( decimal >= 1 )
    {
    resto = decimal % 2;
    binario[indice--] = resto;
    decimal = decimal / 2;
    }

    for(int indice=0;indice<=6;indice++)
      printf("  %d", binario[indice]);

    printf("\n" );
}
