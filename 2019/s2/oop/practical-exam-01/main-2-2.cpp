#include <iostream>
#include <cmath>
using namespace std;
extern int binary_to_number(int digits[], int num_digits);
int main(){
int digits[4]={1,0,1,0};
int num = 4;
cout<< binary_to_number(digits,num)<<endl;
return 0;
}