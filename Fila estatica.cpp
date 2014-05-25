                              /*FILA ESTATICA*/
/* Implementação realizada em aula pelo Prof. Marcello Bonfim

OPERAÇÕES IMPLEMENTADAS:
          - INICIALIZAR FILA
          - INSERIR NA FILA
          - RETIRAR ELEMENTO DA FILA
          - CONSULTAR ELEMENTO NA FILA
          - APRESENTAR ELEMENTOS DA FILA
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


typedef struct tipoElemento { 
       int elemento;
}TElemento;

typedef struct tipoFila
{
       TElemento dados[100];
       int tamanhoFila;
}TFila;


/************************************************************************/
void linha()
{ 
     int i;
     for (i=1;i<=80;i++)
     printf("_");
     printf("\n");
}

void cabec()
{ 
     system("cls");
     printf("Exemplo - Fila Estatica\n");
     linha();
}
/************************************************************************/
/* Função para inicializar fila estática*/
void inicializarFila(TFila *pFila)
{
     pFila->tamanhoFila = 0;
}

/************************************************************************/
/* Funcao para inserir um novo elemento no final da fila */
void inserir (TFila *pFila)
{ 
        cabec();
        
        if (pFila->tamanhoFila < 100)
        {
            printf("\n Informe valor: ");
            scanf("%d",&pFila->dados[pFila->tamanhoFila].elemento);
            pFila->tamanhoFila++;
            printf("\n\nInserido com Sucesso!!!!\n\n");
            }
        else /* Fila cheia*/
             printf("\n\nFila cheia, elemento nao inserido!!!!\n\n");
        
}
/************************************************************************/
/* Consultar um primeiro cliente da fila */
void consultar(TFila *pFila)
{ 
    int achou = 0;
    int pesquisa;
    cabec();
    
    printf("\nConsulta elemento da fila\n");
    if (pFila->tamanhoFila != 0)
    {
        printf("\n Informe valor a ser pesquisado: ");
        scanf("%d", &pesquisa);
        
        int posicao = 0;
        while (posicao != pFila->tamanhoFila && achou == 0)
        {
              if (pFila->dados[posicao].elemento == pesquisa)
                 achou = 1;
              else
                 posicao++;
        }
        if (achou == 1)
           printf("\n Elemento encontrado: %d", pFila->dados[posicao].elemento);
        else
           printf("\n Elemento nao encontrado na fila");
    }
    else
        printf("\n\nA fila está vazia!!\n\n");
    
    printf("\n\nTecle enter para voltar para o menu\n");
    getch();
}
/************************************************************************/
/* remover um cliente da fila */
void excluir (TFila *pFila)
{ 
    int i;
    cabec();
    
    printf("\n Retira primeiro elemento da fila \n");
    if (pFila->tamanhoFila != 0) // verifica se tem elementos na fila
    { 
        for (i=0; i<pFila->tamanhoFila; i++)
        {
           pFila->dados[i] = pFila->dados[i+1];
        }
        pFila->tamanhoFila--;
        printf("\n\n Retirado da fila com sucesso!!!!\n\n");
    }
    else // fila vazia
         printf("\n\nFila vazia!!\n\n");
    getch();
}
/************************************************************************/
/* Lista todos os clientes da fila */
void listar (TFila *pFila)
{ 
     cabec();
     printf("\nListagem de elementos da fila\n");
     if (pFila->tamanhoFila != 0)
     { 
        printf("\n\n Elemento\n");
        printf("-------------------------------------------------------\n");
        for (int i=0; i < pFila->tamanhoFila; i++)
            printf("%4d \n", pFila->dados[i].elemento);
        
        printf("-------------------------------------------------------\n");
        printf("\n\nQuantidade de elementos na fila = %d\n",pFila->tamanhoFila);
     }
     else
         printf("\n\n Fila vazia!");
     
     printf("\n\n\nTecle enter para voltar para o menu\n");
     getche();
}

/************************************************************************/
// Programa principal
int main()
{ 
    TFila fila;
    int opcao;
    inicializarFila(&fila);
    
    do { 
        cabec();
        printf("\nOpcoes: ");
        printf("\n\n 1 - Inserir elemento na fila");
        printf("\n\n 2 - Consultar elemento da fila");
        printf("\n\n 3 - Retirar primeiro elemento da fila");
        printf("\n\n 4 - Listar todos os elementos da fila");
        printf("\n\n 0 - para sair \n");
        linha();
        printf("\nEntre com a sua opcao: ");
        scanf("%d", &opcao); /* Le a opcao do usuario */
        switch (opcao)
        { 
               case 1: inserir(&fila); break;
               case 2: consultar(&fila);break;
               case 3: excluir(&fila); break;
               case 4: listar(&fila); break;
               case 0: break;
               default: printf("\nOpcao nao valida");
        }
    } while (opcao != 0);
}
