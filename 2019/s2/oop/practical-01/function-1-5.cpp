int count_even(int number){
	int num_even=0;
	for(int i=1; i<=number;i++){
		if(i%2 == 0){
			num_even= num_even+1;
		}
	}
return num_even;
}