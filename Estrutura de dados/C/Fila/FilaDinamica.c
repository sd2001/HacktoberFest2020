#include "FilaDinamica.h"



int main()
{
	int opc;
	t_Library biblioteca;


	for(;;)
	{
		printf("1 - Adicionar Livro\n");
		printf("2 - Remover Livro\n");
		printf("3 - Mostrar Livro\n");
		printf("0 - Sair\n\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opc);

		if(opc == 1)
		{
			createBook(&biblioteca);
		}
		else if(opc == 2)
		{
			if(verificarFila(&biblioteca))
			{
				removeFila(&biblioteca);
			}
			else
			{
				printf("Fila vazia .....\n");
				system("PAUSE");
			}
		}
		else if(opc == 3)
		{
			if(verificarFila(&biblioteca))
			{
				showFila(&biblioteca);
			}
			else
			{
				printf("Fila vazia .....\n");
				system("PAUSE");
			}
		}
		else if(opc == 0)
		{
			printf("Saindo....\n");
			exit(0);
		}

		system("cls");
	}


	return 0;
}
