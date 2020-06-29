#include <stdio.h>
#include <stdlib.h>


void main()
{
  FILE *arq;
  FILE *saida;
  char LinhaEntrada[20];
  char *result;
  char arquivosaida[40];
  int valor,a, validador;
  int EstadoInicial = 1;
  int EstadoFinal = 4;
  int EstadoAtual[20] = { [0 ... 19] = 0 };
  int Entrada[20] = { [0 ... 19] = 0 };
  
  a = 0;
  EstadoInicial = 1;
  EstadoAtual[0] = 1;
  EstadoFinal = 4;


  saida = fopen("Saida.txt", "w");                   //cria o arquivo novo, para apagar o arquivo anterior
  fclose(saida);                                     //fecha o arquivo
  
  
  arq = fopen("Entrada.txt", "rt");                  //Abre um arquivo TEXTO para LEITURA
  if (arq == NULL)                                   //Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  saida = fopen("Saida.txt", "a");                   //Abre um arquivo TEXTO para ESCRITA
  fprintf(saida, "Estado Inicial -> %i\n", EstadoInicial);     //Escreve no arquivo o valor do estado inicial


  while (!feof(arq))                                 //feof indica quando chegou ao fim do arquivo
  {
	    result = fgets(LinhaEntrada, 3, arq);          //o 'fgets' lê a linha, até 3 caracteres ou até o '\n'
      valor = atof(result);                          //converte valor do ponteiro result para int, para comparação no switch
      Entrada[a] = valor;

      fprintf(saida, "Simbolo lido -> %i\n", valor); //Escreve no arquivo o valor da entrada


      switch (valor)                                 //dependendo da entrada, seleciona o andamento dos estados
      {
        case 0:
          if (EstadoAtual[1] == 2)                   //se já tiver o segundo estado, altera ele para 3
        {
          EstadoAtual[1] = 3;
          fprintf(saida, "Estado correte -> %i e %i \n", EstadoAtual[0],EstadoAtual[1]);  //Escreve no arquivo o valor dos estados
        }
          else
          fprintf(saida, "Estado correte -> %i\n", EstadoAtual[0]);   //Escreve no arquivo o valor dos estados
        break;

        case 1:{
          if (EstadoAtual[1] == 3)                  //com a entrada 1, estando no estado 3, altera ele para 4
            {
               EstadoAtual[1] = 4;
               fprintf(saida, "Estado correte -> %i e %i \n", EstadoAtual[0],EstadoAtual[1]);   //Escreve no arquivo o valor dos
               validador =1;                        //variavel para controle de chegada no estado final, saindo do while
            }

          else {
             if (EstadoAtual[0] == 1)                  //com a entrada 1, estando no estado 3, altera ele para 4
              { 
              EstadoAtual[0] = 1;                   //com a entrada 1, estando no estado 1, mantem ele em 1 
              EstadoAtual[1] = 2;                   //com a entrada 1, estando no estado 1, cria o estado 2
              fprintf(saida, "Estado correte -> %i e %i \n", EstadoAtual[0],EstadoAtual[1]);   //Escreve no arquivo o valor dos estados
              }

                       
             else          
              fprintf(saida, "Estado correte -> %i\n", EstadoAtual[0]);   //Escreve no arquivo o valor dos
             


           }
          
        break;
    
          }

       if (validador ==1)                            //sai do while caso já tenha chegado ao estado final antes do final da fila
        break;
   

        a++;
      }
  }
 fclose(arq);                                       //fecha o arquivo


if (EstadoAtual[1] == EstadoFinal)                  //compara o estado 2 ao final para dar a resposta   
     { 
       printf("\n\nAutomato aceito");
       fprintf(saida, "\n\nAutomato aceito!\n");    //Escreve no arquivo quando o automato não foi aceito
     }
  else
    { printf("\n\nAutomato não aceito");
      fprintf(saida, "\n\nAutomato não aceito!\n");       //Escreve no arquivo quando o automato não foi aceito
    }  
fclose(saida);                                      //Fecha o arquivo



}
