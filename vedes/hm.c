#include <stdio.h>
#include <stdlib.h>

int
main ()
{
	double **tm;

	tm = (double**) malloc(5 * sizeof(double *));

	for(int i = 0; i<5; ++i)
		tm[i] = (double *) malloc((i+1) * sizeof(double));

	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < i+1; ++j) 
			tm[i][j] = i * (i + 1) / 2 + j;

	for(int i = 0; i < 5; ++i){ 
		for(int j = 0; j < i+1; ++j)
			printf("%f ",tm[i][j]);		
		printf("\n");	
	}
	
	printf("\n");
	
	(*(tm + 2))[1] = 14.0;
	*(*(tm + 2) + 2) = 15.0;
	
	for(int i = 0; i < 5; ++i){ 
		for(int j = 0; j < i+1; ++j)
			printf("%f ",tm[i][j]);		
		printf("\n");	
	}

	for(int i = 0; i < 5; ++i) free(tm[i]);

	free(tm);	
	
	return 0;
}
