/*   AL2 - Professor Leonardo Vianna

	 Listas din�micas*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o de constantes
#define TRUE 1
#define FALSE 0

//declara��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declara��o de prot�tipos
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
int main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int opcao, num1, num2;
	
	do
	{
		//exibindo o menu ao usu�rio
		opcao = menu ();
		
		switch (opcao)
		{
			//inser��o
			case 1: printf ("Entre com o n�mero a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o inserido!\n");
					}
					break;
				
			//remo��o
			case 2: printf ("Entre com o n�mero a ser removido: ");
			        scanf ("%d", &num1);
			        
			        if (remover (&L, num1))
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o removido!\n");
					}
					break;
				
			//alterar
			case 3: printf ("Entre com o n�mero a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("Entre com o novo elemento: ");
			        scanf ("%d", &num2);
			        
			        if (alterar (L, num1, num2))
			        {
			        	printf ("Elemento alterado!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o alterado!\n");
					}
					break;
				
			//buscar
			case 4: printf ("Entre com o n�mero a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        if (buscar (L, num1))
			        {
			        	printf ("Elemento encontrado!\n");
					}
					else
					{
						printf ("Elemento n�o encontrado!\n");
					}
					break;
				
			//exibir
			case 5: exibir (L);
			        break;
				
			//sa�da
			case 6: printf ("Fim do programa!");
			        break;
			        
			//op��o inv�lida
			default: printf ("Op��o inv�lida! Tente novamente.");
		}
		
		system ("pause");
	}
	while (opcao != 6);
}

//implementa��o das fun��es
int inserir (TLista *L, int numero)
{
	//passo 1: alocar mem�ria para o novo elemento
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	if (aux == NULL)  //se n�o foi poss�vel alocar mem�ria
	{
		return FALSE;
	}
	else
	{
		//passo 2: guardar o valor na nova caixa
		aux->valor = numero;
		
		//passo 3: mandar o prox do novo N� apontar para o at� ent�o primeiro elemento da lista
		aux->prox = *L;
		
		//passo 4: fazer o L apontar para o novo elemento
		*L = aux;
		
		return TRUE;
	}
}

int remover (TLista *L, int numero)
{
}

int alterar (TLista L, int velho, int novo)
{
	TLista aux = L;
	int cont = 0;
	
	while (aux)  //while (aux != NULL)
	{
		if (aux->valor == velho)
		{
			aux->valor = novo;
			cont++;
		}
		aux = aux->prox;
	}
	
	if (cont == 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
	
	//return cont;
}

int buscar (TLista L, int numero)
{
	TLista aux = L;

	while (aux)
	{
		if (aux->valor == numero)
		{
			return TRUE;
		}
		
		aux = aux->prox;
	}	
	
	return FALSE;
}

void exibir (TLista L)
{
	TLista aux = L;
	
	if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{	
	    printf ("Lista: ");
		while (aux != NULL)
		//while (aux)
		{
			printf ("%d ", aux->valor);
			aux = aux->prox;
		}
		printf ("\n");
	}
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de op��es:\n\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
	printf ("(4) Buscar\n(5) Exibir\n(6) Sair\n\n");
	printf ("Entre com a sua op��o: ");
	scanf ("%d", &op);
	
	return op;
}
