#include <iostream>
using namespace std;

extern int* readNumbers(int n);
extern void semesterNames(int *semesters,int length);
int main()
{
	int n=3;
	int *ptr = readNumbers(n);
	int length =3;
	semesterNames(ptr,length);
	delete [] ptr;
	return 0;

}