#include <iostream> 
#include <string> 
#include "cart.h" 
#include "meerkat.h" 
using namespace std; 
cart::cart() 
{
  	counts=0; 
} 
bool cart::addMeerkat(meerkat cat) 
{  
	if (counts==4)   
	return false;   
	else   
	{    
		m[counts++]=cat;   
	}  
}  
void cart::emptyCart()  
{   
	for (int i=0;i<counts;i++)    
	m[i].~meerkat();   
	counts=0;  
}  
void cart::printMeerkats()  
{   
	for (int i=0;i<counts;i++)   
	{            
		cout<<m[i].getName()<<" "<<m[i].getAge()<<endl;   
	}  
}  














