#include <iostream>
using namespace std;
void cpyia(int old_array[],int new_array[],int len){
	int* old_a= &old_array[0];
	int* new_a= &new_array[0];
	for (int i=0; i<len; i++){
		*(new_a+i)=*(old_a+i);
	}
	
	}