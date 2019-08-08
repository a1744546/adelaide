#include <iostream>
#include <string> 
using namespace std;
void print_as_binary(std::string decimal_number){

int n = std::stoi(decimal_number);


int a[100],i=0;

	while(n>0){
		a[i]=n%2;
		i++;
		n = n/2;
	}
	for(i--;i>=0;i--){
	cout<<a[i];
}

	cout<<endl;



}