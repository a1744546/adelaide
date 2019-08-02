int maximum(int array[],int n){
	int num = array[0];
	for(int i=1; i<n;i++){
		if(num<array[i]){
			num = array[i];
		}
	}
return num;


}