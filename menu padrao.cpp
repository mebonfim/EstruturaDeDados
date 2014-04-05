#include "stdio.h"
#include "stdlib.h"
#include "conio.h"


// Programa principal
int main()
{ 
  	int opcao;

	do 
    { 
         printf("\nOpcoes: \n\n");
         printf(" 1 - Inserir novo numero \n");
         printf(" 2 - Consultar numero \n");
         printf(" 3 - Remover numero \n");
         printf(" 4 - Listar todos os numeros \n");
		 printf(" 0 - para sair \n\n");
         printf("Entre com a sua opcao: ");
         scanf("%d", &opcao); /* Le a opcao do usuario */
         switch (opcao)
         { 
                case 1: inserir(&lista); break;
                case 2: consultar(&lista); break;
				case 3: remover(&lista); break;
                case 4: listar(&lista); break;
				case 0: break;
                default: printf("\n\n Opcao invalida"); getch(); break;
         }
    } while (opcao != 0);
}

