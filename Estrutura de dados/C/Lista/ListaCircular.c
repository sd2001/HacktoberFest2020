#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>//para a função sleep
#include <string.h>
#define MAX 10

typedef struct
{
	char nome[50];
	int idade;
} Date;

typedef struct
{
	int comeco;
	int fim;
	int QuabtIntens;
	Date INFO[MAX];//Quantidade de elementos que tem vai ter dentro do vetor
} Circle;

typedef struct
{
	char login[MAX];
	char senha[MAX];
} Password;

void InicializaPassword(Password *vet)
{
	strcpy(vet->login, "JOBS");
	strcpy(vet->senha, "JOBS123");
}

/*Inicializa a lista circular*/
void IniciarLista(Circle *Roster)
{
	Roster->comeco = 0;
	Roster->fim = -1;
	Roster->QuabtIntens = 0;
}

/*Verifica se a senha esta ou não cadastrada*/
bool VerificacaoDeSenha(Password *Verificar)
{
	bool p = false;
	Password log;

	printf("Entre com o seu login\n");
	scanf("%s", log.login);
	printf("Entre com sua senha\n");
	scanf("%s", log.senha);
	system("cls");

	if(!strcmp(log.login, Verificar->login))
	{
		if(!strcmp(log.senha, Verificar->senha))
		{
			p = true;
		}
	}

	return p;
}

/*Verifica se o vetor/ lista esta cheio*/
bool ListaCheia(Circle *Roster)
{
	if(Roster->QuabtIntens == MAX)
	{
		return true;
	}

	return false;
}

/*Verifica se a lista esta vazia*/
bool ListaVazia(Circle *Roster)
{
	if(Roster->QuabtIntens == 0)
	{
		return true;
	}

	return false;
}

/*Inseri um elemento no começo da lista circular*/
void InserirNaLista(Circle *Roster)
{

	if(!ListaCheia(Roster))
	{
		if(Roster->fim == MAX - 1)
		{
			Roster->fim = -1;
		}

		Roster->fim++;
		setbuf(stdin, NULL);
		printf("Entre com seu nome\n");
		scanf("%[^\n]s", Roster->INFO[Roster->fim].nome);
		printf("Qual a sua idade: ");
		scanf("%d", &Roster->INFO[Roster->fim].idade);
		Roster->QuabtIntens++;
	}
	else
	{
		printf("Lista Cheia....\n");
		system("PAUSE");
	}
	system("cls");
}

/*Remove um elemento do final da lista*/
void RemoverElementoDaLista(Circle *Roster)
{
	if(!ListaVazia(Roster))
	{
		if(Roster->comeco == MAX)
		{
			Roster->comeco = 0;
		}
		Roster->QuabtIntens--;
		Roster->comeco++;
	}
	else
	{
		printf("Lista Vazia.......\n");
		system("PAUSE");
	}

	system("cls");
}


/*Mostra todos os elementos da lista*/
void MostrarLista(Circle *Roster)
{

	int cont, i;
	if(!ListaVazia(Roster))
	{

		for(cont = 0, i = Roster->comeco; cont < Roster->QuabtIntens; cont++)
		{
			printf("Nome: %s\n", Roster->INFO[i].nome);
			printf("Idade: %d\n", Roster->INFO[i].idade);
			printf("\n");
			i++;
			if(i == MAX)
			{
				i = 0;
			}
		}
	}
	else
	{
		printf("Lista Vazia.....\n");
	}

	system("PAUSE");
	system("cls");
}

/*Mostra o menu de opções*/
void Menu()
{
	printf("1 - Inserir\n");
	printf("2 - Excluir\n");
	printf("3 - Mostrar\n");
	printf("0 - Sair\n");
	printf("\n");
}

void BarraDeCarregamento()
{
	int i, j;
	system("mode con:cols=140 lines=40");
	printf ("\n\nCarregando: \n\n");
	system ("color C");

	for (i = 0; i <= 100; i++)
	{
		printf ("\r  %d%%", i);
		printf ("  %d%%\r", i);
		fflush (stdout);

		for (j = 0; j < i; j++)
		{
			if (!j)
				printf (" ");
			printf ("%c", 219);
		}
		printf ("  %d%%", i);
	}

	printf ("\n\n\r \t\t\t\t  CARREGADO....\n\n\n");
	sleep(3);
	system("cls");
}

int main()
{
	Password veri;
	Circle vet;
	bool p = false;
	int opc, m = 3;

	InicializaPassword(&veri);
	IniciarLista(&vet);

	while(m <= 3)
	{
		if(VerificacaoDeSenha(&veri))
		{
			BarraDeCarregamento();
			for(;;)
			{
				Menu();
				printf("Escolha uma opcao: ");
				scanf("%d", &opc);
				system("cls");
				switch(opc)
				{
				case 1:
					InserirNaLista(&vet);
					break;
				case 2:
					RemoverElementoDaLista(&vet);
					break;
				case 3:
					MostrarLista(&vet);
					break;
				case 0:
					printf("Saindo.......\n");
					sleep(5);
					p = true;
					break;
				default:
					printf("Opcao Invalida.....\n");
					system("PAUSE");
					system("cls");
					break;
				}

				system("cls");
				if(p)
				{
					system("cls");
					exit(0);
				}
			}
		}
		else
		{
			printf("Senha ou Login incorreto. Tente Novamente\n");
			printf("Voce tem %d tentativas\n", m);
			system("PAUSE");
			system("cls");
			m--;
		}
	}


	return 0;
}
