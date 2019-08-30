extern int* readNumbers();
extern void hexDigits(int*,int);

int main()
{
	int length=10;
	int* ptr = readNumbers();
	hexDigits(ptr,length);
	delete [] ptr;
	return 0;

}