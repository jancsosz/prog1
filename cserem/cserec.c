#include <stdio.h>

int main(){

	int a = 5;
   	int b = 10;

	printf("a=%d",a);
	printf(" b=%d",b);
	printf("\n");

	b = b + a;
 	a = b - a;
   	b = b - a;

	printf("a=%d",a);
	printf(" b=%d",b);
	printf("\n");

	b = b - a;
   	a = a + b;
  	b = a - b;

	printf("a=%d",a);
	printf(" b=%d",b);
	printf("\n");

//----------

	a = a ^ b;
   	b = a ^ b;
  	a = a ^ b;

	printf("a=%d",a);
	printf(" b=%d",b);
	printf("\n");

}

