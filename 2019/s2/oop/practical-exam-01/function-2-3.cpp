#include <cmath>
#include <iostream>
using namespace std;
bool is_a_palindrome(int integers[], int length){
	for(int i=0;i<length/2;i++){
	if(integers[i] != integers[length-1-i]){
	return 0;	
	}else{
		return 1;
}
}
}
int sum_elements(int integers[], int length){
	int sum = 0;
	
		
		for(int i=0;i<length;i++){
			sum = sum + integers[i];
		}
	
return sum;
}
int sum_if_a_palindrome(int integers[], int length){
	int num = is_a_palindrome(integers,length);
	if(num == 1){
	int sum =0;
	sum = sum_elements(integers,length);
	
	return sum;
	}else{ 
		return -1;
	}
}