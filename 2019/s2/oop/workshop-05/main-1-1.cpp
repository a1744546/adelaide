extern int* readNumbers();
extern void printNumbers(int*,int);
int main(){
	int length = 10;
	int* ptr = readNumbers();
	printNumbers(ptr,length);

	delete [] ptr;
	return 0;
}