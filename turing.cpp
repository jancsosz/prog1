#include <iostream>

using namespace std;

void getDec(int dec){

	

}

void unaris(int dec){
	
	int c = 0;
	cout<<"Az unaris szam:";
	for(int i = 0; i<dec; i++) 
	{
		cout<<"1";
		c++;
		if((c % 5 == 0) && (c != 0)) cout<<" ";
	}
	cout<<endl;

}

int main(){

	int dec;	
	
	cout<<"Adjon meg egy decimalis szamot!"<<endl;
	cin>>dec;

	unaris(dec);	

}
