#include <stdio.h>
#include <stdlib.h>
#define MAX 50


/* Uma pilha que guarda dados de uma biblioteca */

typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int numberStock;
	int id_book;
	int yearLaunch;
} t_Livro;

typedef struct date
{
	t_Livro book;
	struct date *prox;
} t_Date;

typedef struct
{
	t_Date *begin;
} t_Library;


// --------------------- Funções -----------------------

void initialize(t_Library *libry)
{
	libry->begin = NULL;
}

int lenStack(t_Library *libry)
{
	t_Date *aux = libry->begin;
	int value = 0;

	while(aux != NULL)
	{
		value++;
		aux = aux->prox;
	}

	return value;
}

void addElementStack(t_Library *libry, t_Livro books)
{
	t_Date *aux = libry->begin;
	t_Date *newElement;

	newElement = (t_Date*)malloc(sizeof(t_Date));
	newElement->book = books;


	if(libry->begin == NULL)
	{
		libry->begin = newElement;
		newElement->prox = NULL;
	}
	else
	{
		libry->begin = newElement;
		newElement->prox = aux;
	}

	printf("OK\n");
}

void createBook(t_Library *libry)
{
	t_Livro book_aux;

	book_aux.id_book = lenStack(libry);
	setbuf(stdin, NULL);
	printf("What's the name of the book ?\n");
	scanf("%[^\n]s", book_aux.nameBook);
	setbuf(stdin, NULL);
	printf("What's the name of the author ?\n");
	scanf("%[^\n]s", book_aux.nameAuthor);
	printf("Quantity in stock ?\n");
	scanf("%d", &book_aux.numberStock);
	printf("Which year of release ?\n");
	scanf("%d", &book_aux.yearLaunch);

	addElementStack(libry, book_aux);
}

void removeElement(t_Library *libry)
{

	if(libry->begin == NULL)
	{
		printf("Empty Stack\n");
		return;
	}
	else
	{
		t_Date *eliminar = libry->begin;

		libry->begin = eliminar->prox;
		free(eliminar);
		printf("OK\n");
	}
}

void ShowTop(t_Library *libry)
{
	if(libry->begin == NULL)
	{
		printf("Empty Stack\n");
		return;
	}
	else
	{
		t_Date *aux = libry->begin;

		printf("ID: %d\n", aux->book.id_book);
		printf("Name Book: %s\n", aux->book.nameBook);
		aux = aux->prox;

	}
}




















