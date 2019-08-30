#include <iostream>
using namespace std;         
extern void cpyda(double *,double *,int length);

int main(void){
	double oldA[2][3]={1,2,3,4,5,6};
	double newA[2][3]={9,8,7,6,5,4};
	int length = 6;

	double *old_array=&oldA[0][0];
	double *new_array=&newA[0][0];
	cpyda(old_array,new_array,length);
	return 0;

} 