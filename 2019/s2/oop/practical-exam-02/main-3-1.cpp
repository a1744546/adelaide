#include <iostream>
using namespace std;

extern int* readNumbers(int n);
extern bool palindrome(int *numbers,int length);
int main(){
	int n=4;
	int *ptr = readNumbers(n);
	int length =4;
	palindrome(ptr,length);
	cout<<palindrome(ptr,length)<<endl;
	delete [] ptr;
	return 0;


}