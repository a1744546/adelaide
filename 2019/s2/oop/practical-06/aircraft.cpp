#include <iostream>
#include <string>
#include "person.h"
#include "aircraft.h"
using namespace std;
aircraft::aircraft()
{
	callsign=" ";
}
aircraft::aircraft(string Callsign,person thePilot,person theCoPilot)
{
    callsign=Callsign;
    pilot = thePilot;
    copilot=theCoPilot;
}
void aircraft::setPilot(person thePilot)
{
	pilot = thePilot;
}
void aircraft::setCoPilot(person theCoPilot)
{
	copilot=theCoPilot;
}
void aircraft::printDetails()
{
	cout<< callsign <<endl;
	cout<< pilot.getName() <<endl;
	cout<< copilot.getName() <<endl;
}
person aircraft::getCoPilot()
{
	return copilot;
}
person aircraft::getPilot()
{
	return pilot;
}
aircraft::~aircraft()
{
	
}