#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *ifile = fopen("input.txt", "r");
	int m, i = 1;
	char n;
	
	do {
		fscanf(ifile, "%d%c", &m, &n);
		printf("%d %d\n", i, m);
		i++;
	} while(n != '\n');
	
	return 0;
}
