#include <cmath>
int binary_to_number(int digits[], int num_digits){
	int num = 0;
	int j =0;
	for(int i=0;i<num_digits;i++){
		num = num + digits[num-i-1]*pow(2,j);
		j++;
	}
return num;
}