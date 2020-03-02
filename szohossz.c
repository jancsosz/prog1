#include <stdio.h>

int main()
{
	int a=1;
	int db=1;
	while ((a <<= 1)) {++db;}
	printf("%d",db);
	printf("\n");

}
