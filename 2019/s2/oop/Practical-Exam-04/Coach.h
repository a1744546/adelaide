#include "Person.h"
#ifndef COACH_H
#define COACH_H
class Coach: public Person{
private: static nextID;
public:
	Coach();
	Coach(string n, int s1);
	int get_salary();
	~Coach();
private:
	static int nextID;	
};
#endif