#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINHAS 1000000000
#define MAXCOLUNAS 6
#define INFINITO 2000000000

void troca(int v[], int i, int j)
{
	int aux;
	aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void ordenar_por_selecao(int x[], int n)
{
	int menor, pos;
	int i, k = 0;

	while (k < n)
	{
		menor = INFINITO;
		for (i = k; i < n; i++)
		{
			if(x[i] < menor)
			{
				menor = x[i];
				pos = i;
			}
		}
		troca(x, k, pos);
		k++;
	}
}

int main(int argc, char const *argv[])
{
	FILE *arq = fopen("cartelas.txt", "r");
	FILE *arq_aux = fopen("auxiliar.txt", "w");
	int cartela_atual[6];
	int num_cartela = 1;
	int cartela_venc[6] = {6, 9, 22, 23, 48, 52};
	int cartela_lost[6] = {4, 8, 15, 16, 23, 42};

	while(!feof(arq)) 
	{
		int cont;

		for (int i = 0; i < 6; i++)
			fscanf(arq, "%d ", &cartela_atual[i]);
		
		ordenar_por_selecao(cartela_atual, 6);
		fprintf(arq_aux, "ordenada: ");			
		for (int i = 0; i < 6; i++)
			fprintf(arq_aux, "%d ", cartela_atual[i]);
		fprintf(arq_aux, "\n");

		for (cont = 0; cont < 6; cont++)
		{
			if(cartela_atual[cont] != cartela_venc[cont])
				break;
		}
		if (cont == 6)
			printf("\na cartela %d eh vencedora!", num_cartela);

		for (cont = 0; cont < 6; cont++)
		{
			if(cartela_atual[cont] != cartela_lost[cont])
				break;
		}
		if (cont == 6)
			printf("\na cartela %d eh perdedora.", num_cartela);
		num_cartela++;
	}

	fclose(arq);
	fclose(arq_aux);
	return 0;
}