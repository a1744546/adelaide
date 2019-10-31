#include "Player.h"
#include <iostream>
#include "Person.h"
using namespace std;
int Player::nextID = 1000;
Player::Player():Person("","player",0)
{
nog =0;
personID = nextID;
nextID++;
}
Player::Player(string n, int sl, int *list, int m):Person(n,"player",sl)
{
list1 = list;
nog = m;
personID = nextID;
nextID++;
}
int Player::searchGame(int x)
{
	int a = -1;
	for(int i=0;i<nog;i++)
	{
		if(list1[i] == x)
		{
			a = i;
			
		}

	}
	return a+1;
}
int Player::get_salary()
{
	if(serviceLength<20){
		return salary;

	}
else{
	return (3*salary);
	}
}
Player::~Player(){

}