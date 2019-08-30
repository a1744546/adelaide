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

void secondSmallestSum(int* numbers, int length)
{
	for(int i=0;i<length;i++)
	{
		for(int j=i;j<length;j++)
		{
			cout<<"{";
			for(int k=i;k<j+1;k++)
			{
				cout<<numbers[k];
				if(k != j){
					cout<<",";
				}
			}
		if(j==length-1)
		{
			cout << "}" << endl;
		}else
		{
			cout << "}" << ",";
		}
		} 
	cout<<endl;
	}

}