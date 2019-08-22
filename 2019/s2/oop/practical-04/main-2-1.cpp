#include <iostream>
using namespace std;
extern void print_sevens(int*,int);
int main(void){
	int length=9;
	int array[9]={1,2,3,4,5,6,7,8,9};
	int* ptr = &array[0];
	print_sevens(ptr,length);
	return 0;
}