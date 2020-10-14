#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MAX_PILHA 10

/* Uma pilha que guarda dados de uma biblioteca */

typedef struct
{
	char nameBook[MAX];
	char nameAuthor[MAX];
	int numberStock;
	int id_book;
	int yearLaunch;
} t_Livro;


void showBook(t_Livro b[], int aux);
void addElementStack(t_Livro b[], int *aux);
void revomeElementStack(int *aux);

int main()
{
	t_Livro book[10];
	int esc, aux = -1;

	for(;;)
	{
		printf(" 1 - Add element to the stack\n");
		printf(" 2 - Delete element from stack\n");
		printf(" 3 - Shows elements of the stack\n");
		printf(" 4 - Stack size\n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &esc);

		switch(esc)
		{
		case 1:
			addElementStack(book, &aux);
			break;
		case 2:
			if(aux == -1)
			{
				printf("Empty stack\n");
				break;
			}

			revomeElementStack(&aux);
			break;
		case 3:
			if(aux == -1)
			{
				printf("Empty stack\n");
				break;
			}

			showBook(book, aux);
			break;
		case 4:
			printf("The stack has size %d\n", aux + 1);
			break;
		case 0:
			exit(0);
		default:
			printf("invalid value\n");
			break;
		}

		//system("PAUSE");
		//system("cls");
	}


	return 0;
}


void addElementStack(t_Livro b[], int *aux)
{
	t_Livro book_aux;

	*aux = *aux + 1;

	book_aux.id_book = *aux + 1;

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

	b[*aux] = book_aux;
}

void revomeElementStack(int *aux)
{
	*aux = *aux - 1;
}

void showBook(t_Livro b[], int aux)
{
	printf("ID: %d\n", b[aux].id_book);
	printf("Name: %s\n", b[aux].nameBook);
	printf("Author: %s\n", b[aux].nameAuthor);
	printf("Number: %d\n", b[aux].numberStock);
	printf("Year: %d\n", b[aux].yearLaunch);
	printf("\n");

}


























