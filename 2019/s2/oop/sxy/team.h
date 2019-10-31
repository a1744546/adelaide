
#ifndef team.h
#define team.h
#include <iostream>
class team: public player{

player mumber[50];
public:
	int number;
	int check;
	string Name;
Team();                            // default constructor
Team(int max_size,string name);  // constructor with given team size and team name

// returns the number of players who have joined the team
int get_current_number_of_players(); 

std::string get_name();                // returns the team's name

Player * get_roster();       


bool add_player(Player new_player);

~Team();



};
#endif