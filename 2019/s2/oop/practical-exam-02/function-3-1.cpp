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
bool palindrome(int *numbers,int length)
{
	for(int i=0;i<length/2;i++)
	{
		if(numbers[i] != numbers[length-1-i])
			{
				return false;
			}
		else
			{
		return true;
			}
	}
}
