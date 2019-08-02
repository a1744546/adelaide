#include<iostream>
using namespace std;
extern int sumtwo(int array[],int secondarray[],int n);
int main(){
	int a1[5]= {1,2,3,4,5};
	int a2[5]= {6,7,8,9,0};
	cout<<sumtwo(a1,a2,5)<<endl;
return 0;
}