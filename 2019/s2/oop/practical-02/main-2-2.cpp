#include <iostream>
#include <cmath>
using namespace std;

extern int binary_to_number(int binary_digits[], int num_digits);

int main(){


int digits[5]={1,1,0,1,0};
int num = 5;
cout<< binary_to_number(digits,num)<<endl;

return 0;
}