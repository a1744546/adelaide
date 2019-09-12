#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
class Player{
	public:
		int number;
		string name;
		Player();                  // a default constructor 
		Player(int jNumber, std::string pName);    // a constructor that takes the jersey number and player name
		std::string get_name();        // returns the name of the player
		int get_jersey_number();  // returns the player's jersey number
		~Player();                //A default destructor



};

#endif