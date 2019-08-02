int sumtwo(int array[],int secondarray[],int n){
	int sum=0;
		for(int i=0;i < n;i++){
			sum = sum +array[i];
		}

		for(int j=0; j < n;j++){
			sum = sum +secondarray[j];
		}
	return sum;
}