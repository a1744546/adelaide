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
int *reverseArray(int *numbers,int length)
{
	int *rev_num = new int [length];
	for(int i=0;i<length;i++)
	{
			rev_num[i] = numbers[length-1-i];
	}
return rev_num;
} 
void printNumbers(int *numbers,int length){
	for(int i=0;i<length;i++)
	{ 
		cout<<i<<" "<<numbers[i]<<endl;
	}

}