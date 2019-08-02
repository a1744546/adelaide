#include<iostream>
double average(int array[],int n){
    double average = 0;
    for (int i=0;i<n;i++){
        if (n<1){
            return 0;
        }else{
            average = average + array[i];
            
        }
    }
    return average/n;
}
