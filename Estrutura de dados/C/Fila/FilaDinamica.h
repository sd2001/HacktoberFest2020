#include <stdio.h>
#include <stdlib.h>
#define MAX 50


typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int year;
	int id;
} t_Book;

typedef struct data
{
	t_Book livros;
	struct data *prox;
} t_Date;

typedef struct
{
	t_Date *inicio;
	t_Date *fim;
} t_Library;


void inicarFila(t_Library *library)
{
	library->inicio = NULL;
	library->fim = NULL;
}

int sizeQueue(t_Library *library)
{
	int value = 0;
	t_Date *aux = library->inicio;

	while(aux != NULL)
	{
		value++;
		aux = aux->prox;
	}

	return value;
}

void entrarNaFila(t_Library *library, t_Book book_aux)
{
	t_Date *aux = library->fim;
	t_Date *newBook;

	newBook = (t_Date*)malloc(sizeof(t_Date));
	newBook->livros = book_aux;
	newBook->prox = NULL;


	//Lista Vazia
	if(library->inicio == NULL)
	{
		library->inicio = newBook;
		library->fim = newBook;
	}
	else
	{
		aux->prox = newBook;
		library->fim = newBook;
	}
}

void createBook(t_Library *library)
{
	t_Book book;

	setbuf(stdin, NULL);
	printf("Entre com o nome do livro\n");
	scanf("%[^\n]s", book.nameBook);

	setbuf(stdin, NULL);
	printf("Entre com o nome do autor\n");
	scanf("%[^\n]s", book.nameAuthor);

	printf("Qual o ano de lancamento do livro: ");
	scanf("%d", &book.year);

	book.id = sizeQueue(library) + 1;

	entrarNaFila(library, book);
}

int verificarFila(t_Library *library)
{
	if(library->inicio == NULL)
	{
		return 0;
	}

	return 1;
}

void showFila(t_Library *library)
{
	t_Date *aux = library->inicio;


	while(aux != NULL)
	{
		printf("ID: %d\n", aux->livros.id);
		printf("Nome do Livro: %s\n", aux->livros.nameBook);
		printf("Nome do autor: %s \n", aux->livros.nameAuthor);
		printf("Ano de lancamento: %d\n", aux->livros.year);
		aux = aux->prox;
	}

	system("PAUSE");
	system("cls");
}


void removeFila(t_Library *library)
{
	t_Date *eliminar = library->inicio;

	library->inicio = eliminar->prox;
	free(eliminar);
}



















