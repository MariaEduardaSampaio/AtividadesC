#include <stdio.h>
#include <stdlib.h>

float **alocaMatriz (int n)
{
	float **M = (float**)malloc(n*sizeof(float*));

	for (int i = 0; i < n; i++)
		M[i] = (float*)malloc(n*sizeof(float));

	return M;
}

void preencheMatriz(float **M, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			M[i][j] = 0.0;
	}
}

void imprimeMatriz(float **M, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%2.1f ", M[i][j]);
		printf("\n");
	}
}

void liberaMatriz(float **M, int n)
{
	for (int i = 0; i < n; i++)
		free(M[i]);

	free(M);
}

int main()
{
	int n = 0;
	float **M = NULL;

	printf("\nentre com um numero n da matriz nxn: ");
	scanf("%d", &n);

	if (n>0)
	{
		M = alocaMatriz(n);
		preencheMatriz(M, n);
		imprimeMatriz(M, n);
		liberaMatriz(M, n);
	}
	return 0;
}