// 2013 - Lista estática ordenada.cpp : main project file.

#include "stdio.h"
#include "conio.h"
#include "string.h"
#define MAX 100

typedef struct elemento
{
       int valor;
}TElemento;

typedef struct tipoLista
{
        TElemento dados[MAX];
        int tamanhoLista;
}TLista;

void inicializarLista (TLista *pLista)
{
     pLista->tamanhoLista = 0;
}

// Inserir um novo elemento na lista
void inserir(TLista *pLista)
{ 
    int novoValor; 
    int i;
	  int posicao;
    printf("\nInserir Novo Elemento\n");
    if (pLista->tamanhoLista < MAX) // verifica se o vetor pode receber novo aluno
    { 
	      printf("\n Informe Valor: ");
        scanf("%d",&novoValor);
        
        posicao = -1; //VARIAVEL DE CONTROLE DE POSICAO
        if (pLista->tamanhoLista == 0)  //PRIMEIRO ELEMENTO DA LISTA
           pLista->dados[0].valor = novoValor;
        else
        { 
            for (i=0; i < pLista->tamanhoLista; i++)  
            { 
                if (novoValor < pLista->dados[i].valor)  //SE CODIGO LIDO FOR MENOR QUE 
                {                                   //OS EXISTENTES NA LISTA
                   posicao = i;
                   break;
                }
            }
            if (posicao == -1) //CASO SEJA O ELEMENTO A SER INSERIDO SEJA MAIOR QUE OS 
               pLista->dados[pLista->tamanhoLista].valor = novoValor;			//EXISTENTES NA LISTA
            else
            { 
                for (i = pLista->tamanhoLista; i > posicao; i--) 
			          {
                    pLista->dados[i] = pLista->dados[i-1]; //LAÇO PARA DESLOCAR OS DADOS, ABRINDO ESPAÇO
                }							// PARA A INSERÇÃO DO NOVO ELEMENTO
                pLista->dados[posicao].valor = novoValor;  //INSERE O NOVO ELEMENTO NA POSICAO (EM ORDEM)
            }
        }
        pLista->tamanhoLista++; //A CADA NOVO ELEMENTO INSERIDO, INCREMENTA-SE
        printf("\n\n Elemento Inserido com Sucesso!!!\n");
    }
    else // CASO A LISTA ESTEJA CHEIA...
    { 
         printf("\n\n Nao Pode Inserir - Lista Cheia!!!\n");
         getch();
    }
}


void consultar(TLista *pLista)
{
    int pesquisado;
    int i;
    int achou;
    
    printf("\nEntre com o valor a ser pesquisado: ");
    scanf("%d", &pesquisado);
    i = 0;
    achou = 0;
    while (i < pLista->tamanhoLista && achou == 0)
    {
          if (pLista->dados[i].valor == pesquisado)
          {   
		          achou = 1; //encontrou 
          }
          else
          {
              i++;
          }
    }
    if (achou == 1)
    {
       printf("\n Elemento: %d", pLista->dados[i].valor);
    }   
    else
        printf("%d nao foi localizado", pesquisado);
      
}



void excluir(TLista *pLista)
{
    int pesquisado;
    int i;
    int achou;
    int opcao;

    printf("\nEntre com o valor a ser excluido: ");
    scanf("%d", &pesquisado);
    i = 0;
    achou = 0;
    while (i < pLista->tamanhoLista && achou == 0)
    {
          if (pLista->dados[i].valor == pesquisado)
          {   
		          achou = 1; //encontrou 
          }
          else
              i++;
    }
    if (achou == 1) 
    {
       printf("\n Elemento: %d", pLista->dados[i].valor);
       printf("\n\nExclui registro? [1]Sim / [2]Nao");
       scanf("%d", &opcao);
       if (opcao == 1)
       {
              while (i < pLista->tamanhoLista)
              {
                    pLista->dados[i] = pLista->dados[i+1];
                    i++;
              }
              pLista->tamanhoLista--;
       }
       
    }   
    else
        printf("%d nao foi localizado", pesquisado);
    
}     

void apresentar(TLista *pLista)
{
     printf("\n\n----------LISTAGEM GERAL------------");
     for (int i=0; i < pLista->tamanhoLista; i++)
     {
		     printf("\n %d o. Elemento: %d", i+1, pLista->dados[i].valor);
     }
	   printf("\n\n------------------------------------");
	   getch();
}



int main()
{
    int opcao;
    
    //cria lista
    TLista lista;
    
    inicializarLista(&lista);
    
    do
    {
        printf("\n\n-------CADASTRO DE ELEMENTOS--------\n");
        printf("\n1 - Cadastro");
        printf("\n2 - Pesquisa");
        printf("\n3 - Listagem");
        printf("\n4 - Excluir");
        printf("\n0 - Sair");
        printf("\nEscolha opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
      			case 1: inserir(&lista); break;
      			case 2: consultar(&lista); break;
      			case 3: apresentar(&lista); break;
      			case 4: excluir(&lista); break;
      			case 0: break;
      			default: printf("\n\nOpcao Invalida!");
  		}
    }while (opcao != 0);
}
