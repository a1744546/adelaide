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

void semesterNames(int *semesters,int length)
{
	for(int i=0;i<length;i++)
	{
		
			switch(semesters[i])
			{
				case 1:
				cout<< i << " " << semesters[i] << " "<<"Semester 1"<< endl;
				break;
				case 2:
				cout<< i << " " << semesters[i] << " "<<"Semester 2"<< endl;
				break;

				case 3:
				cout<< i << " " << semesters[i] << " "<<"Trimester 1"<< endl;
				break;

				case 4:
				cout<< i << " " << semesters[i] << " "<<"Trimester 2"<< endl;
				break;
				case 5:
				cout<< i << " " << semesters[i] << " "<<"Trimester 3"<< endl;
				break;	

			}

		
	}
}