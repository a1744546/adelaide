#include<iostream>
using namespace std;
void count_numbers(int array[4][4]){	
int a =0, b = 0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
 	
 	for(int m =0;m<4;m++){
 		for(int z=0;z<4;z++){
 		switch(array[i][z]){
 			case 0:a++;
 			break;
 			case 1:b++;
 			break;
 			case 2:c++;
 			break;
 			case 3:d++;
 			break;
 			case 4:e++;
 			break;
 			case 5:f++;
 			break;
 			case 6:g++;
 			break;
 			case 7:h++;
 			break;
 			case 8:i++;
 			break;
 			case 9:j++;
 			break;
 		}
 	}
 	
}
cout<< "0:" << a << ";1:" << b << ";2:"<< c << ";3:"<< d << ";4:"<< e << ";5:"<< f<< ";6:"<<g<< ";7:"<< h<< ";8:"<< i<< ";9:"<< j<<";"<<endl ;
}