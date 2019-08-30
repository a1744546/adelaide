#include <iostream>

extern int* readNumbers();
extern void secondSmallestSum(int*, int);

int main(){
	int length =3;
	int* ptr = readNumbers();
	secondSmallestSum(ptr,length);
	delete [] ptr;
	return 0;
}