#include <iostream>
extern int* readNumbers();
extern bool equalsArray(int *numbers1,int *numbers2,int length);
int main()
{
	int* ptr1 = readNumbers();
	int* ptr2 = readNumbers();
	int length = 3;
	std::cout<<equalsArray(ptr1,ptr2,length);
	delete [] ptr2,ptr1;
	return 0;
}