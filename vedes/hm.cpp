#include <iostream>

int
main ()
{
	double **tm;

	tm = new double * [5];

	for(int i = 0; i<5; ++i)
		tm[i] = new double[i + 1];

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

	for(int i = 0; i < 5; ++i) delete[] tm[i];

	delete[] tm;	
	
	return 0;
}
