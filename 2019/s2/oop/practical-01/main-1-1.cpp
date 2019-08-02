#include<iostream>
using namespace std;
extern int sum_array(int*,int);
int main(){
    int array[5]={1,2,3,4,5};
    cout << sum_array(array,5) << std::endl;
    return 0;
}
