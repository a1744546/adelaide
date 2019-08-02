#include<iostream>
using namespace std;
extern int count(int*, int,int);
int main(){
    
    int array[4]={1,2,3,4};
    cout << count(array,4,3) <<endl;
    return 0;
}
