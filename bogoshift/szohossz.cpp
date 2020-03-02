#include <iostream>

int main()
{
	int a=1;
	int db=0;

	while (a!=0)
	{
		a<<=1;
		++db;
    }

	std::cout<<db<<std::endl;

}
