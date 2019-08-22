#include <iostream>
using namespace std;
void print_sevens(int* num, int length){
	for (int i=0; i<length; i++){
		if(*(num+i)%7==0){
			cout<<*(num+i)<<endl;
		}
	}
	
}