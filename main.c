#include <stdio.h>
#include <stdlib.h>


void main()
{
  FILE *arq;
  FILE *arq2;
  char LinhaEntrada[10];
  char *result;
  int valor,a, validador;
  int EstadoInicial = 1;
  int EstadoFinal = 4;
  int EstadoAtual[10] = { [0 ... 9] = 0 };
  int Entrada[10] = { [0 ... 9] = 0 };
  
  a = 0;
  EstadoInicial = 1;
  EstadoAtual[0] = 1;
  EstadoFinal = 4;
  


  
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("Entrada.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

   
  while (!feof(arq))//feof indica quando chegou ao fim do arquivo
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(LinhaEntrada, 3, arq);  // o 'fgets' lê até 3 caracteres ou até o '\n'
      valor = atof(result); //converte valor do ponteiro result para int, para comparação no switch
      Entrada[a] = valor;


      printf("\n\nValor %i ",valor);
      printf("\nEntrada %i ",Entrada[a]);
      


      switch (valor)
      {
        case 0:
          if (EstadoAtual[1] == 2)
        {
          EstadoAtual[1] = 3;
        }
        break;

        case 1:{
          if (EstadoAtual[1] == 3)
            {
               EstadoAtual[1] = 4;
               validador =1;
            }

          else 
             { 
              EstadoAtual[0] = 1;
              EstadoAtual[1] = 2;
           }
        }
          
        break;
    
      }

      if (validador ==1)
      {
        break;
      }
   

    a++;
 }
 
 fclose(arq);


printf("\n\n\nEntrada 1 %i ",Entrada[0]);
printf("\nEntrada 2 %i ",Entrada[1]);
printf("\nEntrada 3 %i ",Entrada[2]);
printf("\nEntrada 4 %i ",Entrada[3]);
printf("\nEntrada 5 %i ",Entrada[4]);
printf("\nEntrada 6 %i ",Entrada[5]);

printf("\n\n\nEstado atual 1 %i ",EstadoAtual[0]);
printf("\nEstado atual 2 %i ",EstadoAtual[1]);
printf("\nEstado atual 3 %i ",EstadoAtual[2]);
printf("\nEstado atual 4 %i ",EstadoAtual[3]);
printf("\nEstado atual 5 %i ",EstadoAtual[4]);
printf("\nEstado atual 6 %i ",EstadoAtual[5]);
printf("\nEstado atual 7 %i ",EstadoAtual[6]);



if (EstadoAtual[1] == EstadoFinal)    
     { 
       printf("\n\nAutomato aceito");
   }
  else
{ printf("\n\nAutomato não aceito");
}  



}
