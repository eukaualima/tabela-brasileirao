/*
=---------------=
=-> Cabeçalho <-=
=---------------=
*/
/**
 * @author Kauã dos Santos Lima
 * @since 28/11/2023
 * @version 28/11/2023
 * @todo Criação de um algoritmo recursivo para retornar dados da tabela do Brasileirão Série A
 **/

/*
=--------------=
=-> Includes <-=
=--------------=
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
=----------------=
=-> Estruturas <-=
=----------------=
*/
struct time
{
	char nome[100];
	int pontos;
	int posicao;
};

typedef struct time T_TIME;

/*
=------------------=
=-> Subprogramas <-=
=------------------=
*/
// < Função para fazer a busca de times e suas respectivas posições >
int buscar(T_TIME t[], char nome[], int i)
{
	if (i > 19)
	{
		printf("[!] Este time não existe na tabela.\n");
		system("PAUSE");
		return -1;
	}
	else if (strcasecmp(nome, t[i].nome) == 0)
	{
		printf("Time encontrado! Gerando informacoes...\n");
		return i;
	}
	else
	{
		return buscar(t, nome, i+1);
	}
}

// < Procedimento para impressão do time >
void imprimir(T_TIME t[], int i)
{
	printf("\n\nPosicao: %i\nTime: %s\nPontos: %i\n\n", t[i].posicao, t[i].nome, t[i].pontos);
	system("PAUSE");
}

// < Função para mostrar os 5 primeiros colocados >
int primeiros(T_TIME t[], int i)
{
	if (i > 4)
	{
		system("PAUSE");
		return 0;
	}
	else
	{
		printf("%i.\t%s\t%i\n", t[i].posicao, t[i].nome, t[i].pontos);
		return primeiros(t, i+1);
	}
}

// < Função para mostrar os 5 últimos colocados >
int ultimos(T_TIME t[], int i)
{
	if (i >= 15 && i < 20)
	{
		printf("%i.\t%s\t%i\n", t[i].posicao, t[i].nome, t[i].pontos);
		return ultimos(t, i+1);
	}
	else if (i > 19)
	{
		system("PAUSE");
		return 0;
	}
	else
	{
		return ultimos(t, i+1);
	}
}

// < Função para calcular a diferença de pontos entre o primeiros colocados >
int diferencaPrimeiros(T_TIME t[], int i)
{
	// < Declaração de variáveis locais >
	int diferenca;
	
	if (i > 4)
	{
		system("PAUSE");
		return 0;
	}
	else
	{
		diferenca = t[i].pontos - t[i+1].pontos;
		printf("%s tem %i pontos a mais que %s\n", t[i].nome, diferenca, t[i+1].nome);
		return diferencaPrimeiros(t, i+1); 
	}
}

// < Função para calcular a diferença de pontos entre o últimos colocados >
int diferencaUltimos(T_TIME t[], int i)
{
	// < Declaração de variáveis locais >
	int diferenca;
	
	if (i >= 15 && i < 19)
	{
		diferenca = t[i].pontos - t[i+1].pontos;
		printf("%s tem %i pontos a mais que %s\n", t[i].nome, diferenca, t[i+1].nome);
		return diferencaUltimos(t, i+1); 
	}
	else if (i > 19)
	{
		system("PAUSE");
		return 0;
	}
	else
	{
		return diferencaUltimos(t, i+1); 
	}
}

// < Função para mostrar a metade dos times >
int mostrarMetade(T_TIME t[], int i)
{
	if (i > 9)
	{
		system("PAUSE");
		return 0;
	}
	else
	{
		printf("%i.\t%s\t%i\n", t[i].posicao, t[i].nome, t[i].pontos);
		return mostrarMetade(t, i+1);
	}
}

// < Procedimento para ordenar os times de acordo com a classificação atual >
void selectionSort(T_TIME v[], int n)
{
	// < Declaração de variáveis locais >
	int i, im; // im = índice de maior valor;
	T_TIME tmp;
	
	if (n > 1)
	{
		// < Zera o maior valor >
		im = 0;
		
		for (i = 1; i < n; i++)
		{
			if (v[i].posicao > v[im].posicao)
			{
				im = i;
			}
		}
		
		// < Faz a troca >
		if (im != n-1)
		{
			tmp = v[n-1];
			
			v[n-1] = v[im]; // Move o maior para o final
			v[im] = tmp;
		}
		
		selectionSort(v, n-1);
	}
}


// < Procedimento para o usuário controlar o que deseja fazer >
void menu(T_TIME t[])
{
	// < Declaração de variáveis locais >
	char nome[100];
	int opcao, posicao;
	
	// < Loop do menu >
	do 
	{
		printf(">-----------------<[ B R A S I L E I R A O ]>-----------------<\nEscolha abaixo uma das opcoes que deseja acessar:\n[1]: Buscar um time e sua posicao\n\t=> Veja em qual posição da serie A seu time esta.\n[2]: 5 primeiros colocados\n\t=> Verifique os times mais bem colocados.\n[3]: 5 ultimos colocados.\n\t=> Verifique os times que estao na zona de rebaixamento.\n[4]: Diferenca de pontos entre os 5 primeiros.\n\t=> Saiba a diferenca de pontos entre os primeiros colocados.\n[5]: Diferenca de pontos entre os 5 ultimos.\n\t=> Saiba a diferenca de pontos entre os ultimos colocados.\n[6]: 10 primeiros times.\n\t=> Reordena os times e mostra metade dos times com base nos pontos.\n[0]: Sair do programa\n\t=> Fecha o programa.\n\nSua escolha: ");
		scanf("%i", &opcao);
		
		switch(opcao)
		{
			case 1:
				// < Entrada de dados >
				printf("Time para buscar: ");
				scanf("%s", nome);
				
				// < Faz a busca recursivamente >
				posicao = buscar(t, nome, 0);
				
				// < Imprime o resultado da busca >
				if (posicao >= 0)
				{
					imprimir(t, posicao);
				}
				break;
				
			case 2:
				selectionSort(t, 19);
				primeiros(t, 0);
				break;
				
			case 3:
				selectionSort(t, 19);
				ultimos(t, 0);
				break;
				
			case 4:
				selectionSort(t, 19);
				diferencaPrimeiros(t, 0);
				break;
				
			case 5:
				selectionSort(t, 19);
				diferencaUltimos(t, 0);
				break;
			
			case 6:
				selectionSort(t, 19);
				mostrarMetade(t, 0);
				break;
			
			case 0:
				exit(1);	
				break;
				
			default:
				printf("[!] Escolha uma opção válida.\n");
				break;
		}
	} while (opcao != 0);
}

/*
=------------------------=
=-> Programa Principal <-=
=------------------------=
*/
int main (void)
{
	// < Declaração de variáveis locais >
	T_TIME t[20];
	
	// < Adição dos times no vetor t >
	strcpy(t[0].nome, "Athletico-PR");
	t[0].pontos = 52;
	t[0].posicao = 8;
	
	strcpy(t[1].nome, "America-MG");
	t[1].pontos = 21;
	t[1].posicao = 20;
	
	strcpy(t[2].nome, "Atletico-MG");
	t[2].pontos = 60;
	t[2].posicao = 4;
	
	strcpy(t[3].nome, "Botafogo");
	t[3].pontos = 62;
	t[3].posicao = 3;
	
	strcpy(t[4].nome, "Fluminense");
	t[4].pontos = 53;
	t[4].posicao = 7;
	
	strcpy(t[5].nome, "Bragantino");
	t[5].pontos = 59;
	t[5].posicao = 6;
	
	strcpy(t[6].nome, "Gremio");
	t[6].pontos = 59;
	t[6].posicao = 5;
	
	strcpy(t[7].nome, "Palmeiras");
	t[7].pontos = 63;
	t[7].posicao = 1;
	
	strcpy(t[8].nome, "Cuiaba");
	t[8].pontos = 48;
	t[8].posicao = 9;
	
	strcpy(t[9].nome, "Sao Paulo");
	t[9].pontos = 47;
	t[9].posicao = 10;
	
	strcpy(t[10].nome, "Vasco da Gama");
	t[10].pontos = 42;
	t[10].posicao = 16;
	
	strcpy(t[11].nome, "Fortaleza");
	t[11].pontos = 45;
	t[11].posicao = 12;
	
	strcpy(t[12].nome, "Corinthians");
	t[12].pontos = 44;
	t[12].posicao = 14;
	
	strcpy(t[13].nome, "Cruzeiro");
	t[13].posicao = 13;
	t[13].pontos = 44;
	
	strcpy(t[14].nome, "Santos");
	t[14].pontos = 43;
	t[14].posicao = 15;
	
	strcpy(t[15].nome, "Internacional");
	t[15].pontos = 46;
	t[15].posicao = 11;
	
	strcpy(t[16].nome, "Bahia");
	t[16].pontos = 41;
	t[16].posicao = 17;
	
	strcpy(t[17].nome, "Goias");
	t[17].pontos = 35;
	t[17].posicao = 18;
	
	strcpy(t[18].nome, "Coritiba");
	t[18].pontos = 29;
	t[18].posicao = 19;
	
	strcpy(t[19].nome, "Flamengo");
	t[19].pontos = 63;
	t[19].posicao = 2;
	
	// < Chama o menu >
	menu(t);
	
	return 0;
	
}
