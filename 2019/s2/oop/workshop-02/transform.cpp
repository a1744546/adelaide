#include<iostream>
using namespace std;
int main(){
	int n,a[100],num,i=0;
	n = 73;
	while(n>0){
		a[i]=n%2;
		i++;
		n = n/2;
	}
for(i--;i>=0;i--){
cout<<a[i];

}


cout<<endl;


return 0;
}