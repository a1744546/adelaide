#include "Person.h"
#include <string>
#include "Coach.cpp"
#include <iostream>
using namespace std;

Coach::Coach():Person("","coach",0)
{
	personID = nextID;
    nextID++;
}

int Coach::nextID = 0;
Coach::Coach(string n, int s1):Person(n,"coach",sl)
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
	return 3*salary;
	}
}
Coach::~Coach()
{

}