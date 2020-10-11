#include "FilaDuplamenteEncadeada.h"

int main()
{
	t_Library library;
	int esc;

	iniciar(&library);

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
			createBook(&library);
		}
		else if(esc == 2)
		{
			removerElementList(&library);
		}
		else if(esc == 3)
		{
			showList(&library);
		}
		else if(esc == 4)
		{
			searchList(&library);
		}
		else if(esc == 5)
		{
			printf("A lista tem %d elementos\n", quantidadeDeElementos(&library));
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
