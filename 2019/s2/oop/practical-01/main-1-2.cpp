#include<iostream>
extern double average(int*,int);
using namespace std;
int main(){
    int array[5]={1,2,3,4,5};
    cout << average(array,5) <<endl;
    return 0;
}
