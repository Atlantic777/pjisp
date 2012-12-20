#include <stdio.h>
#include <stdlib.h>

int** init_poly(int);
void load_poly(int**, int, FILE*);
void print_poly(int**, int);

int main()
{
	FILE *in = fopen("input.txt", "r");

	int deg, i;
	fscanf(in, "%d ", &deg);

	int **poly_1 = init_poly(deg);
	load_poly(poly_1, deg, in);
	print_poly(poly_1, deg);

	return 0;
}

int** init_poly(int deg)
{
	int i;
	int **p = calloc(deg, sizeof(int*));

	for(i = 0; i<deg; i++)
		p[i] = calloc(2, sizeof(int));
	
	return p;
}

void load_poly(int** p, int deg, FILE* in)
{
	int i;
	for(i = 0; i<deg; i++)
	{
		p[i][0] = i;
		fscanf(in, "%d ", &p[i][0]);
	}
}

void print_poly(int** p, int deg)
{
	int i;
	for(i = 0; i<deg; i++)
		printf("%dx^%d ", p[i][0], i);
	puts("");
}
