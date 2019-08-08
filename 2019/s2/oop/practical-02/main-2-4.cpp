#include <iostream>
using namespace std;

extern int sum_min_and_max(int integers[], int length);

int main(){


int array[8]={1,2,3,4,5,6,7,8};

cout<< sum_min_and_max(array,8)<<endl;

return 0;
}