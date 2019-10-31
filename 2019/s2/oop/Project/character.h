#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;
class character{
public:
character();
void create_name();
void create_data();
string get_name();
int get_character_inital_attack();
int get_character_inital_defense();
void update_main_character();
~character();
public:
	std::string character_name;
	int character_attack;
	int character_defense;
	int total_character_data;
};
#endif
