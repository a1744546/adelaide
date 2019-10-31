#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "character.h"
#include <ctime>
#include <cstdlib>
using namespace std;
character::character(){
	character_attack = 0;
	character_defense=0;
	total_character_data = 20;
	character_name = "null";
}
void character::create_name(){
	cout<<"enter your name"<<endl;
	cin>>character_name;

}
void character::create_data(){
	cout<<"enter the attack value(your attack value must less than 20)"<<endl; 
       cin>>character_attack;
       
       character_defense = total_character_data-character_attack;
}
string character::get_name(){
	return character_name;
}
int character::get_character_inital_attack(){
	return character_attack;
}
int character::get_character_inital_defense(){
	return character_defense;
}
void character::update_main_character(){
	character_defense = character_defense+0.5;
	character_attack = character_attack+0.5;
}
character::~character(){

}