#include <cmath>
int binary_to_number(int binary_digits[], int number_of_digits){
	int num = 0;
	int j =0;
	for(int i=0;i<number_of_digits;i++){
		num = num + binary_digits[number_of_digits-i-1]*pow(2,j);
		j++;
	}

return num;
}