#include <iostream>
using namespace std;

extern int* readNumbers(int n);
extern int sumSubArrays(int *numbers,int length);
int main(){
int n=3;
	int *ptr = readNumbers(n);
	int length =3;
	cout<< sumSubArrays(ptr,length)<<endl;
	delete [] ptr;
	
	return 0;

}
