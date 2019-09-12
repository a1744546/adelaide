#include <iostream>
#include "Player.h"
using namespace std;
Player::Player()
{
	name = "null";
	number = 0;	
}
Player::Player(int jNumber, std::string pName)
{
	name = pName;
	number = jNumber
}    // a constructor that takes the jersey number and player name
string Player::get_name(){
	return name;
}        // returns the name of the player
int Player::get_jersey_number(){
return number;
}  // returns the player's jersey number
Player::~Player(){
}