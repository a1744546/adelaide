#include "Person.h"
using namespace std;
#ifndef COACH_H
#define COACH_H
class Coach: public Person{
private: 
	static int nextID;
public:
	Coach();
	Coach(string n, int sl);
	int get_salary(int serviceLength);
	~Coach();
private:
	static int nextID;	
};
#endif