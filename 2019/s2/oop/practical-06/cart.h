#ifndef cart_h 
#define cart_h 
#include <string> 
#include <iostream> 
#include "meerkat.h" 
class cart 
{  
	meerkat m[4];  
	int counts; 
	public:  
	cart();  
	bool addMeerkat(meerkat cat);
	void emptyCart();
	void printMeerkats();
	 ~cart(); 
	}; 
#endif