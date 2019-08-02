#include<iostream>
#include<cmath>
bool fanarray(int array[], int n){
	if(array[floor(n/2)]>array[floor(n/2)+1] && (array[floor(n/2)]>array[floor(n/2)-1]){
		for (int i = 0; i < n/2; i++)
			if(array[floor(n/2)-i]>array[floor(n/2)-1-i] && 
				(array[floor(n/2)+i]>array[floor(n/2)+1+i]){
				return true;
			}else{return false;
			}
	}else{
		return false;
	}
	
}
