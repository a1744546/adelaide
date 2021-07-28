#include "Person.h"
#include <string>
#include "Coach.h"
#include <iostream>
using namespace std;
int Coach::nextID = 0;

Coach::Coach():Person("","Coach",0)
{
	personID = nextID;
    nextID++;
}


Coach::Coach(string n, int sl):Person(n,"Coach",sl)
{
	personID = nextID;
    nextID++;
}
int Coach::get_salary()
{
	if(serviceLength<15){
		return salary;

	}
else{
	return (3*salary);
	}
}
Coach::~Coach()
{

}