#include <iostream>
using namespace std;
extern int diagonal(int array[4][4]);
int main(){
	int array[4][4]={{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
	cout<<diagonal(array)<<endl;
	
	return 0;
}