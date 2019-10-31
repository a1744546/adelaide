#include <iostream>
#include 'player.h'
#include 'team.h'
using namespace std;
team::Team(){
number = 0;
name = 'null';
check = 0;
}
team::Team(int max_size,string name){
	check = max_size;
	name = name;
}
int team::get_current_number_of_players(){
	return number;
}

string team::get_name(){
	return name;
}

player* team::get_roster(){
	return mumber;
}
bool team::add_player(Player new_player){
	if(number<check){
		mumber[number] = new_player;
		number++;
		return true;
	}
	else{
		return false;
	}
}
team::~team();