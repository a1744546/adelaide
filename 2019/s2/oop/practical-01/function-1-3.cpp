#include<iostream>
int count(int array[],int n,int number){
    int count=0;
    for (int i=0;i<n;i++){
        if (n <= 0 ){
            return 0;
        }else{
            if (array[i]==number){
                count++;
            }
        }
    }
    return count;
}
