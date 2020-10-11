#include <stdlib.h>
#define MAX_NAME 50

typedef struct
{
	int keys;
	char name[MAX_NAME];
} t_Books;

typedef struct info
{
	t_Books livros;
	struct info *prox;
} t_Info;

typedef struct
{
	t_Info *begin;
	t_Info *end;
} Tabela;

void inicitialize(Tabela *comeco)
{
	comeco->begin = NULL;
	comeco->end = NULL;
}

int quantidadeDeElementos(Tabela *comeco)
{
	t_Info *valor = comeco->begin;
	int cont = 0;

	while(valor != NULL)
	{
		cont++;
		valor = valor->prox;
	}

	return cont;
}

void entrarNaTabela(Tabela *comeco, t_Books book)
{
	t_Info *tab = comeco->end;
	t_Info *NewElemento;

	NewElemento = (t_Info*)malloc(sizeof(t_Info));
	NewElemento->livros = book;

	if(comeco-> begin == NULL)
	{
		comeco->begin = NewElemento;
		comeco->end = NewElemento;
		NewElemento->prox = NULL;
	}
	else
	{
		tab->prox = NewElemento;
		NewElemento->prox = NULL;
		tab = NewElemento;
	}
}

void cadastrarLivro(Tabela *comeca)
{
	t_Books book;

	printf("Entre com o nome do livro: ");
	scanf("%s", book.name);
	book.keys = quantidadeDeElementos(comeca) + 1;

	entrarNaTabela(comeca, book);
}

void showElementos(Tabela *comeco)
{
	t_Info *mostrar = comeco->begin;

	while(mostrar != NULL)
	{
		printf("%d - %s \n", mostrar->livros.keys, mostrar->livros.name);
		mostrar = mostrar->prox;
	}
}

void searchElementos(Tabela *comeco)
{
	t_Info *mostrar = comeco->begin;
	int key;

	printf("Entre com o chave do livro: ");
	scanf("%d", &key);

	while(mostrar != NULL)
	{
		if(key == mostrar->livros.keys)
		{
			printf("%d - %s \n", mostrar->livros.keys, mostrar->livros.name);
			return;
		}
		mostrar = mostrar->prox;
	}
	printf("Chave Inexistente");
}

void deleteElementos(Tabela *comeco)
{

	comeco->begin = NULL;
	comeco->end = NULL;
}
