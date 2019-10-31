#include "Person.h"
using namespace std;
#ifndef COACH_H
#define COACH_H
class Coach: public Person{
protected: 
	static int nextID;
public:
	Coach();
	Coach(string n, int sl);
	int get_salary();
	~Coach();
private:
	static int nextID;	
};
#endif