#include <iostream>
using namespace std;
#include "Team.h"
#include "Player.h"
Team::Team(){
size = 0;
check =0;
Name = "null";
}                            
Team::Team(int max_size, string name){
size = max_size;
check =0;
Name = name; 
} 
int Team::get_current_number_of_players()
{
return size;
}

string Team::get_name()
{
	return name;
}                

Player * Team::get_roster(){
return munmber;
}
bool Team::add_player(Player,new_player){
if(size == check){
		return false;
	}else{
		munmber[size] = new_player;
		size++;
		return true;
	}
}


Team::~Team(){
}