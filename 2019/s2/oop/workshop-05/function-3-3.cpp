#include <iostream>
using namespace std;

int* readNumbers()
{
	int* ptr = new int[3];
	for(int i=0; i<3; i++)
	{
		cin >> *(ptr+i);//ptr[i]
	}
	return ptr;
}
bool equalsArray(int *numbers1,int *numbers2,int length)
{
	if(length<1)
	{
		return false;
	}else
	{
		for(int i=0;i<length;i++)
		{
			if(numbers1[i]!=numbers2[i])
			{
				return false;
			}
		}
	}
	return true;
}