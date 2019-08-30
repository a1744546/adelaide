#include <iostream>
using namespace std;

extern int* readNumbers(int n);
extern void printNumbers(int *numbers,int length);
int main()
{
	int n=3;
	int *ptr = readNumbers(n);
	int length =3;
	printNumbers(ptr,3);
	delete [] ptr;
	return 0;
}