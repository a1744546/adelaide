#include "iostream"
#include "string.h"
#include "stdlib.h"
using namespace std;
extern void copy_2d_strings(std::string first[][2],std::string second[][2], int n) ;

int main(void){
	std::string first[3][2]={"z","x","y","q","i","o"};
	std::string second[3][2]={"q","w","l","p","b","a"};
	int n=3;
	copy_2d_strings(first, second, n);
	return 0;
}