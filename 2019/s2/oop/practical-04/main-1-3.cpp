#include <iostream>
using namespace std;
extern void cpyia(int old_array[],int new_array[],int len);

int main(void){
	int old_array[5]={2,3,4,4,0};
	int new_array[5]={9,0,9,5,5};
	int length=5;
	cpyia(old_array,new_array,length);
	return 0;
}