
#ifndef COACH_H
#define COACH_H
#include "Person.h"
using namespace std;
class Coach: public Person{

public:
	Coach();
	Coach(string n, int sl);
	int get_salary();
	~Coach();
private:
	static int nextID;	
};
#endif