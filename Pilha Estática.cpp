#include <stdio.h>
#include <conio.h>

typedef struct tipoDado
{
        int dado;
}TDado;

typedef struct tipoPilha
{
        TDado vetorPilha[100];
        int topo;
}TPilha;
        
void inicializaPilha(TPilha *pPilha)
{
     pPilha->topo = -1;
}

void empilhar(TPilha *pPilha)
{
     if (pPilha->topo < 99)
     {
        pPilha->topo++;
        printf("Informe dado para pilha: ");
        scanf("%d", &pPilha->vetorPilha[pPilha->topo].dado);
     }
     else
     {
         printf("Pilha cheia");
     }
}

void desempilhar(TPilha *pPilha)
{
     if (pPilha->topo > -1)
     {
        pPilha->topo--;
        printf("\nDado desempilhado \n\n");
     }
     else
     {
         printf("Pilha vazia");
     }
}

void apresentarPilha(TPilha *pPilha)
{
     printf("\n\n Dados empilhados");
     for (int i=pPilha->topo; i>=0; i--)
     {
         printf("\n Indice: %d - Valor: %d", i, pPilha->vetorPilha[i].dado);
     }
     getch();
}
   
int main()
{ 
  	int opcao;
  	
  	TPilha pilha;
  	
  	inicializaPilha(&pilha);

    do 
    { 
         printf("\nOpcoes: \n\n");
         printf(" 1 - Empilhar dado \n");
         printf(" 2 - Desempilhar dado \n");
         printf(" 3 - Apresentar dados \n");
         printf(" 0 - para sair \n\n");
         printf("Entre com a sua opcao: ");
         scanf("%d", &opcao); /* Le a opcao do usuario */
         switch (opcao)
         { 
                case 1: empilhar(&pilha); break;
                case 2: desempilhar(&pilha); break;
                case 3: apresentarPilha(&pilha); break;
				        case 0: break;
                default: printf("\n\n Opcao invalida"); getch(); break;
         }
    } while (opcao != 0);
}
        
