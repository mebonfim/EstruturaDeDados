#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo
{
	int info;
	struct tipoNo *proximo;
}TNo;

typedef struct tipoLista
{
	TNo *inicio;
}TLista;

void inicializarLista(TLista *pLista)
{
	pLista->inicio = NULL;
}

void inserir(TLista *pLista)
{
	TNo *novoElemento;
	TNo *atual;
	TNo *anterior;
	
	novoElemento = new TNo;
	
	printf("Informe valor: ");
	scanf("%d", &novoElemento->info);
	novoElemento->proximo = NULL;
	
	if (pLista->inicio == NULL)
	{
		pLista->inicio = novoElemento;
	}
	else
	{
		//se inserção no início
		if (pLista->inicio->info > novoElemento->info)
		{
			novoElemento->proximo = pLista->inicio;
			pLista->inicio = novoElemento;
			
		}
		else
		{
			atual = pLista->inicio;
			anterior = pLista->inicio;
			
			while (atual != NULL)
			{
				if (atual->info > novoElemento->info)
				{
					anterior->proximo = novoElemento;
					novoElemento->proximo = atual;
					break;
				}
				else
				{
					anterior = atual;
					atual = atual->proximo;
				}
				
			}
			if (atual == NULL)// se inserção no final da lista
			{
				anterior->proximo = novoElemento;
			}
		}
	}
}

void apresentar(TLista *pLista)
{
	TNo *aux;
	aux = pLista->inicio;
	
	if (aux == NULL)
	{
		printf("Lista Vazia!");
	}
	else
	{
		while (aux != NULL)
		{
			printf("\n Elemento: %d", aux->info);
			aux = aux->proximo;
		}
	}
	getch();
}

void consultar (TLista *pLista)
{
     if (pLista->inicio != NULL)
     {
         int pesquisa;
         printf("\n Informe valor a ser consultado na lista: ");
         scanf("%d", &pesquisa);
         TNo *aux;
         aux = pLista->inicio;
         while (aux != NULL)
         {
               if (aux->info == pesquisa)
               {
                  printf("\n Encontrou: %d \n\n", aux->info);
                  break;
               }
               else
               {
                   aux = aux->proximo;
               }
         }
         if (aux == NULL)
         {
            printf("\n\n Nao encontrado!");
         }
     }
     else
     {
         printf("\n\n Lista vazia!");
     }
}
     
     


void excluir(TLista *pLista)
{
	TNo *atual;
	TNo *anterior;
	
	int pesquisa;
	
	if (atual == NULL)
	{
		printf("\n Lista Vazia!");
	}
	else
	{
		printf("\n Informe valor a ser excluido na lista: ");
		scanf("%d", &pesquisa);
		
		atual = pLista->inicio;
	    anterior = pLista->inicio;
		
		while (atual != NULL)
		{
			if (atual->info == pesquisa)
			{
				if (atual == pLista->inicio)
				{
				    pLista->inicio = pLista->inicio->proximo;
					  free(atual);
				}
				else
                {
						anterior->proximo = atual->proximo;
						free(atual);
				}
				break;
			}
			else
			{
				anterior = atual;
				atual = atual->proximo;
			}
		}
    }
}



// Programa principal
int main()
{ 
  	int opcao;
  	
  	TLista listaEncadeada;
	
	  inicializarLista(&listaEncadeada);
  	
   	do 
    { 
         printf("\nOpcoes: \n\n");
         printf(" 1 - Inserir na lista encadeada ordenada \n");
         printf(" 2 - Apresentar lista encadeada \n");
         printf(" 3 - Excluir elemento da lista encadeada \n");
         printf(" 4 - Consultar elemento da lista encadeada \n");
         printf(" 0 - para sair \n\n");
         printf("Entre com a sua opcao: ");
         scanf("%d", &opcao); /* Le a opcao do usuario */
         switch (opcao)
         { 
                case 1: inserir(&listaEncadeada); break;
                case 2: apresentar(&listaEncadeada); break;
                case 3: excluir(&listaEncadeada); break;
                case 4: consultar(&listaEncadeada); break;
			          case 0: break;
                default: printf("\n\n Opcao invalida"); getch(); break;
         }
    } while (opcao != 0);
}

