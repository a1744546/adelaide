#include<iostream>
using namespace std;
extern bool ascending(int array[], int n);
int main(){
int a[5]={2,3,5,9,11};
cout << ascending(a,5) << endl;
return 0;

}