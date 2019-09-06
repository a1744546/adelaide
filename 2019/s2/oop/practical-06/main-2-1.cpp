#include <iostream>
#include "meerkat.h"
#include "cart.h"
using namespace std;
int main()
{
	meerkat wen;
	wen.setName("wen");
	wen.setAge(5);
	cart wen1;
	if (wen1.addMeerkat(wen))
	{
		
	}
    else
    {
     
    }
    meerkat ray;
	ray.setName("mact");
	ray.setAge(6);
	if (wen1.addMeerkat(ray))
	{
		
	}
	meerkat eric;
	eric.setName("eric");
	eric.setAge(7);
	if (wen1.addMeerkat(eric))
	{
		
	}
    meerkat tim;
    tim.setName("tim");
    tim.setAge(8);
    if (wen1.addMeerkat(tim))
    {
       
    }
    meerkat matt;
    matt.setName("matt");
    matt.setAge(9); 
    if (wen1.addMeerkat(matt))
    {
        wen1.printMeerkats();
    }   
    else
    {
        cout << "the cart is full"<< endl;
        wen1.printMeerkats();
        wen1.emptyCart();
    }	
 	return 0;
}
