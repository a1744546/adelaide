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
int sumSubArrays(int *numbers,int length)
	{ int array[length*(length+1)/2];

			for(int i=0;i<length;i++)
		{ array[i]=0;
			for(int j=i;j<length;j++)
			{
			
				for(int k=i;k<j+1;k++)
				{
					array[i] = array[i]+numbers[k];
				}
			}		
				
				
		
	
		}
		int sum =0;
		for(int i=0;i< length*(length+1)/2;i++){
			sum = sum + array[i];
		}
		return sum;
	}