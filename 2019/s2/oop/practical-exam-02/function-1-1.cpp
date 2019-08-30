#include <iostream>
using namespace std;

int* readNumbers(int n)
{
	int* ptr = new int[n];
	for(int i=0; i<n; i++)
	{
		cin >> ptr[i];
	}
	return ptr;
}
void printNumbers(int *numbers,int length){
	for(int i=0;i<length;i++)
	{ 
		cout<<i<<" "<<numbers[i]<<endl;
	}

}