#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAX_BOOK 20

typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int year;
	int id;
} t_Book;

//Funções
void addElementList(t_Book b[], int *aux);
void removerElement(int *aux);
void showAllElementList(t_Book b[], int aux);
void serachElementtoList(t_Book b[], int aux);


int main()
{
	t_Book library[MAX_BOOK];
	int esc;
	int aux = -1;

	for(;;)
	{
		printf("1 - Adicionar Livro\n");
		printf("2 - Remover Livro \n");
		printf("3 - Mostrar Lista\n");
		printf("4 - Pesquisar Livro\n");
		printf("5 - Quantidade de elemento\n");
		printf("0 - Sair \n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &esc);

		system("cls");

		if(esc == 1)
		{
			addElementList(library, &aux);
		}
		else if(esc == 2)
		{
			removerElement(&aux);
		}
		else if(esc == 3)
		{
			showAllElementList(library, aux);
		}
		else if(esc == 4)
		{
			serachElementtoList(library, aux);
		}
		else if(esc == 5)
		{
			printf("A lista tem %d elementos\n", aux + 1);
		}
		else if(esc == 0)
		{
			exit(0);
		}

		system("PAUSE");
		system("cls");
	}


	return 0;
}


void addElementList(t_Book b[], int *aux)
{
	t_Book book_aux;

	setbuf(stdin, NULL);
	printf("Qual o nome do livro ?\n");
	scanf("%[^\n]s", book_aux.nameBook);
	setbuf(stdin, NULL);
	printf("Qual o nome do autor do livro ?\n");
	scanf("%[^\n]s", book_aux.nameAuthor);
	printf("Qual o ano de Lancamento ?\n");
	scanf("%d", &book_aux.year);

	*aux = *aux + 1;
	book_aux.id = *aux + 1;

	b[*aux] = book_aux;

	printf("Elemento adicionado...\n");

}

void removerElement(int *aux)
{
	if(*aux == -1)
	{
		printf("Lista Vazia\n");
		return;
	}

	*aux = *aux - 1;

	printf("Elemento Removido....\n");
}

void showAllElementList(t_Book b[], int aux)
{
	if(aux == -1)
	{
		printf("Lista Vazia\n");
		return;
	}


	int i;

	for(i = 0; i <= aux; i++)
	{
		printf("ID: %d\n", b[i].id);
		printf("Nome do Livro: %s\n", b[i].nameBook);
		printf("Nome do Autor: %s\n", b[i].nameAuthor);
		printf("Ano de Lancamento: %d\n", b[i].year);
		printf("\n");
	}
}

void serachElementtoList(t_Book b[], int aux)
{
	if(aux == -1)
	{
		printf("Lista Vazia\n");
		return;
	}


	int i, year;

	printf("Quer os livros a partir de qual ano ?\n");
	scanf("%d", &year);


	for(i = 0; i <= aux; i++)
	{
		if(b[i].year >= year)
		{
			printf("ID: %d\n", b[i].id);
			printf("Nome do Livro: %s\n", b[i].nameBook);
			printf("Nome do Autor: %s\n", b[i].nameAuthor);
			printf("Ano de Lancamento: %d\n", b[i].year);
			printf("\n");
		}
	}
}


























