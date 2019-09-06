#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include <string>
#include "person.h"
using namespace std;
class aircraft
{
	public:
	aircraft();
	aircraft(string callsign,person thePilot,person theCoPilot);
	void setPilot(person thePilot);
	person getPilot();
	void setCoPilot(person theCoPilot);
	person getCoPilot();
	void printDetails();
	person pilot;
	person copilot;  
	string callsign;
	~aircraft();
};
#endif 

