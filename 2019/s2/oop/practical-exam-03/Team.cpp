#include <iostream>
using namespace std;
#include "Team.h"
#include "Player.h"
Team::Team(){
number = 0;
check =0;
Name = "0";
}                            
Team::Team(int max_size, string name){
number = 0;
check =max_size;
Name = name; 
} 
int Team::get_current_number_of_players()
{
return size;
}

string Team::get_name()
{
	return Name;
}                

Player * Team::get_roster(){
return munmber;
}
bool Team::add_player(Player new_player){
if(number == check){
		return false;
	}else{
		munmber[number] = new_player;
		number++;
		return true;
	}
}


Team::~Team(){
}
