#include<iostream>
int sum_array(int array[],int n){
    int sum=0;
    for (int i=0;i<n;i++){
        if (n<1){
            return 0;
        }else{
            sum= sum + array[i];
        }
    }
    return sum;
}
