#include Palindrome.h
#include <string>
#include <iostream>
using namespace std;
Palindrome::Palindrome()
{	
	Pa = '';
}
Palindrome::Palindrome(char a)
{
	Pa = a;
}
string Palindrome::removeNonLetters(char B,int b)
{
	char new_Pa[b];
	int j = 0;
	for(int i =0;i<b;i++){
		if(A[i]>='a'&& A[i]<='z'){
			new_Pa[j]=A[i];
			j++;
		}elseif(A[i]>='A'&& A[i]<='Z'){
			new_Pa[j]=A[i];
			j++;

		}

	}

	return new_Pa;
}


string Palindrome::lowerCase(string c)
{
	c = strlwr(c);
	return c;
}
bool Palindrome::isPalindrome(string D,int d)
{
	for(int i=0;i<d,i++)
	{
		if(D[i]!=D[d-i-1])
		{
			cout<< No<< endl;
		}else{
			cout<< Yes << endl;
		}
	}
}