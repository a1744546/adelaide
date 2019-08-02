#include<iostream>
using namespace std;
void twofivenine(int array[], int n){	
int a =0, b = 0,c=0;
 	
 	for(int i =0;i<n;i++){
 		switch(array[i]){
 			case 2:a++;
 			break;
 			case 5:b++;
 			break;
 			case 9:c++;
 			break;
 	} 
}
cout<< "2:" << a << ";5:" << b << ";9:;"<< c <<endl;
}