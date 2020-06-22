#include <stdio.h>
#include <stdlib.h>


void main()
{
  FILE *arq;
  char Linha[10];
  char *result;
  int i,valor,validador;
  
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("Entrada.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  validador = 0;
  
  while (!feof(arq) && validador ==0)//feof indica quando chegou ao fim do arquivo
  {
	// Lê uma linha (inclusive com o '\n')
      
      result = fgets(Linha, 3, arq);  // o 'fgets' lê até 3 caracteres ou até o '\n'

      valor = atof(result); //converte valor do ponteiro result para int, para comparação no switch

    switch ( i )
  {
    case 1 :   //faz comparação conforme o numero da linha
    i++;
    if (valor != 1)    
     { printf("Automato não aceito");
    validador = 1;}
    break;
       
    case 2 :
    i++;
    if (valor != 1)    
     { printf("Automato não aceito");
    validador = 1;}
    break;
    
    case 3 :
    i++;
    if (valor != 1)    
     { printf("Automato não aceito");
    validador = 1;}
    break;
    
    case 4 :
    i++;
    if (valor != 0)    
     { printf("Automato não aceito");
    validador = 1;}
    break;
    
    case 5 :
    i++;
    if (valor != 0)    
    {  printf("Automato não aceito");
    validador = 1;}
    break;
    
    case 6 :
    if (valor == 0)    
      printf("Automato aceito");
    break;
    }
     
  }
  fclose(arq);
  
  return ;
}
