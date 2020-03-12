#include <string>
#include <iostream>
using namespace std;
int main()
{
	string A= "a1sad";
	string* B= new string[5]; 
	
	int j = 0;
	for(int i =0;i<5;i++){
		if(A[i]>='a'&& A[i]<='z'){
			B[j]=A[i];
			j++;
		}

	}
	cout<< B[4]<<endl;
	delete B;
	return 0;
}