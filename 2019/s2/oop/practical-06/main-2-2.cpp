#include <iostream>
#include <string>
#include "person.h"
#include "aircraft.h"
using namespace std;
int main(){
	person A,B,C;
	A.setName("Tom");
	B.setName("Wei");
	C.setName("yumi");
	aircraft air("Adelaide to Shanghai",A,B);	
	air.setPilot(A);
	air.setCoPilot(B);
	air.printDetails();
	air.setPilot(C);
	air.printDetails();
	air.setCoPilot(A);
	air.printDetails();
	return 0;
}