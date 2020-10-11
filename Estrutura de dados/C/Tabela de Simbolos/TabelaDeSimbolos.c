#include <stdio.h>
#include "TabelaDeSimbolos.h"


int main()
{
	int opc;
	Tabela tabSimb;

	inicitialize(&tabSimb);

	while(1)
	{
		printf("1 - Cadastrar Livro\n");
		printf("2 - Limpar Tabela\n");
		printf("3 - Mostrar Livros\n");
		printf("4 - Pesquisar Livro\n");
		printf("Entre com uma opc: ");
		scanf("%d", &opc);

		switch(opc)
		{
		case 1:
			cadastrarLivro(&tabSimb);
			break;
		case 2:
			deleteElementos(&tabSimb);
			break;
		case 3:
			showElementos(&tabSimb);
			break;
		case 4:
			searchElementos(&tabSimb);
			break;
		default:
			printf("Opcao Invalida\n");
			break;
		}
	}

	return 0;
}
