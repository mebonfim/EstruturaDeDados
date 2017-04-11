#include <stdio.h>
#include <conio.h>

typedef struct tipoSenha
{
	int numeroSenha;
	char tipoSenha;
}TSenha;

typedef struct tipoFila
{
	TSenha fila[100];
	int fimDaFila;
}TFila;

void push (TFila *p, char tipoSenha, int *senha)
{
	(*senha)++;
	p->fimDaFila++;
	p->fila[p->fimDaFila].numeroSenha = *senha;
	p->fila[p->fimDaFila].tipoSenha = tipoSenha;
}

void pushPreferencial (TFila *p, char tipoSenha, int *senhaPref)
{
	if (p->fimDaFila == -1) // fila vazia
	{
		p->fimDaFila++;
		(*senhaPref)++;
		p->fila[p->fimDaFila].numeroSenha = *senhaPref;
		p->fila[p->fimDaFila].tipoSenha = tipoSenha;
	}
	else
	{
		if (p->fila[p->fimDaFila].tipoSenha == 'P') //se só tivermos clientes preferenciais
		{
			p->fimDaFila++;
			(*senhaPref)++;
			p->fila[p->fimDaFila].numeroSenha = *senhaPref;
			p->fila[p->fimDaFila].tipoSenha = tipoSenha;
		}
		else
		{
			int indice;
			
			//encontrar índice para inserção
			for (indice = 0; indice <= p->fimDaFila; indice++)
			{
				if (p->fila[indice].tipoSenha == 'C')
					break;
			}
			
			//deslocar elementos na fila, abrindo espaço para nova senha
			p->fimDaFila++;
			for (int i=p->fimDaFila; i>indice; i--)
			{
				p->fila[i] = p->fila[i-1];
			}
			
			//inserir elemento na fila
			(*senhaPref)++;
			p->fila[indice].numeroSenha = (*senhaPref);
			p->fila[indice].tipoSenha = tipoSenha;
		}
	}
}

void inicializarFila (TFila *p)
{
	p->fimDaFila = -1;
}

void apresentarFila (TFila *p)
{
	if (p->fimDaFila >= 0)
	{
		printf("\n\n *** Fila de senhas ***");
		for (int i=0; i <= p->fimDaFila; i++)
		{
			printf("\n Senha: %d", p->fila[i].numeroSenha);
			printf("\n Tipo da Senha: %c", p->fila[i].tipoSenha);
			printf("\n ---------------------------");
		}
	}
	else
	{
		printf("Fila vazia!");
	}
	getch();
}

void pop (TFila *p)
{
	if (p->fimDaFila >= 0)
	{
		printf("\n\n Chamando senha: ");
		printf("\n Senha: %d", p->fila[0].numeroSenha);
		printf("\n Tipo: %c", p->fila[0].tipoSenha);
		
		for (int i=0; i < p->fimDaFila; i++)
		{
			p->fila[i] = p->fila[i+1];
		}
		p->fimDaFila--;
	}
	else
	{
		printf("\n\n Fila Vazia!");
	}
	getch();
}


int main()
{ 
  	int opcao;
  	
  	int senhaComum = 0;
  	int senhaPreferencial = 0;
  	
  	TFila F; //criando fila
  	
  	inicializarFila(&F);
  	
	do 
    {
    	printf("\n ****** SENHAS ******\n");
        printf("\nOpcoes: \n\n");
        printf(" 1 - Senha Comum \n");
        printf(" 2 - Senha Preferencial \n");
        printf(" 3 - Atendimento pelo caixa \n");
        printf(" 4 - Apresentar fila \n");
		printf(" 0 - Sair \n\n");
        printf("Entre com a sua opcao: ");
        scanf("%d", &opcao); /* Le a opcao do usuario */
        switch (opcao)
        {
			case 1: push(&F, 'C', &senhaComum); break;
            case 2: pushPreferencial(&F, 'P', &senhaPreferencial); break;
			case 3: pop(&F); break; // atender o cliente
            case 4: apresentarFila(&F); break;
			case 0: break;
            default: printf("\n\n Opcao invalida"); getch(); break;
        }
    } while (opcao != 0);
}
