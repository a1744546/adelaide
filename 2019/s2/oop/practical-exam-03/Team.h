#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "Player.h"
using namespace std;
	class Team : public Player{
		Player munmber[50];
	public: int size;
	int check;
	string Name;
Team();                            // default constructor
Team(int max_size,string name);  // constructor with given team size and team name

// returns the number of players who have joined the team
int get_current_number_of_players(); 

std::string get_name();                // returns the team's name

Player * get_roster();       


bool add_player(Player,new_player);

~Team();


};

#endif

