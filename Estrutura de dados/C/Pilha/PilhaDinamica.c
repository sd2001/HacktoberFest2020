#include "PilhaDinamica.h"


int main()
{
	t_Library biblioteca;
	int esc;

	initialize(&biblioteca);

	for(;;)
	{
		printf(" 1 - Add element to the stack\n");
		printf(" 2 - Delete element from stack\n");
		printf(" 3 - Shows first elements of the stack\n");
		printf(" 4 - Stack size\n\n");
		printf(" 0 - Exit\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &esc);

		switch(esc)
		{
		case 1:
			createBook(&biblioteca);
			break;
		case 2:
			removeElement(&biblioteca);
			break;
		case 3:
			ShowTop(&biblioteca);
			break;
		case 4:
			printf("The stack has %d elements\n", lenStack(&biblioteca));
			break;
		case 5:
			exit(0);
		default:
			break;
		}
	}

	return 0;
}
