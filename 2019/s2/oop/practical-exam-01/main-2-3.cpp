#include <iostream>
#include <cmath>
using namespace std;
extern int sum_if_a_palindrome(int integers[], int length);
int main(){
	int array[4]={1,0,0,1};
	int length = 4;
	cout<<sum_if_a_palindrome(array,length)<<endl;
	return 0;
}