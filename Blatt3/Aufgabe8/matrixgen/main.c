#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **matrix;

void allocMatrix(int n, int m)
{
	matrix = (int**) malloc (n*sizeof(int*));
	int i = 0;
	while (i < n)
	{
		matrix[i] = (int*) malloc(m*sizeof(int));
		i++;
	}

	i = 0;
	int j;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void freeMatrix(int n, int m)
{
	//free speicher
	int i = 0;
	while(i < n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void generateMatrix(int n, int m, int randomArea)
{
	int i = 0;
	int j = 0;
	srand(time(NULL));

	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			matrix[i][j] = (rand() % randomArea) - randomArea/2;
			j++;
		}
		i++;
	}
}

void printLineSeperator(int m)
{
	//newLine
	int j = 0;
	while (j < m)
	{
		printf("+---");
		j++;
	}
	printf("+\n");
}

void printMatrix(int n, int m)
{
	int i = 0;
	int j = 0;
	while (i < n)
	{
		printLineSeperator(m);
		j = 0;
		while (j < m)
		{
			printf("+%3i", matrix[i][j]);
			j++;
		}
		printf("+\n");
		i++;
	}
	printLineSeperator(m);
}

int writeFile(int n, int m)
{
	FILE *datei;

	//öffne das Textdokument (write only)
	datei = fopen ("zahlen.txt", "w");

	if(datei == NULL)
	{
		printf("file error");
		return 1;
	}

	int i = 0;
	int j = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			fprintf(datei, "%i ", matrix[i][j]);
			j++;
		}
		i++;
		fprintf(datei, "\n");
	}
	fclose(datei);
	return 0;
}

int main(int argc, char* argv[])
{
/*	int i = 0;
	while(i < argc)
	{
		printf("Argument %d:  %s\n", i, argv[i]);
		i++;
	}
	printf("argc : %d\n", argc);
*/

	int n = 4;
	int m = 5;

	if(argc >= 3)
	{
		n = atoi(argv[1]);
		m = atoi(argv[2]);
	}
	else
	{
		printf("no arguments.... default : n  = %d, m = %d\n", n, m);
	}


printf("n : %d\n", n);
printf("m : %d\n", m);

printf("starting alloc\n");
	allocMatrix(n, m);
printf("starting generate\n");
	generateMatrix(n, m, 100);
printf("starting print\n");
	printMatrix(n, m);
printf("starting fileWriting\n");
	writeFile(n, m);
printf("starting free\n");
	freeMatrix(n, m);

	


return 0;
}
