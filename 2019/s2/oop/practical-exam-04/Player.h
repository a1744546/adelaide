#ifndef PLAYER_H
#define PLAYER_H
#include "Person.h"
#include <iostream>
using namespace std;
class Player: public Person{
	public:
		Player();
		Player(string n, int sl, int *list, int m);
		int searchGame(int x);
		~Player(); 
		int get_salary();
private:
	static int nextID;
	int *list1;
	int nog;
};
#endif