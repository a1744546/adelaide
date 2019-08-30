#include <iostream>
using namespace std;

extern int* readNumbers(int n);
extern int *reverseArray(int *numbers,int length);
extern void printNumbers(int *numbers,int length);
int main(){
	int n=4;
	int *ptr = readNumbers(n);
	int length =4;
	int *newarray = reverseArray(ptr,length);
	printNumbers(newarray,length);
	delete [] ptr;
	delete [] newarray;
	return 0;
}