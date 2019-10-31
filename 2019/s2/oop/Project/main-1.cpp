#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "character.h"
#include <ctime>
#include <cstdlib>
#include "goblin.h"	
#include "monster.h"
#include "king.h"
using namespace std;
extern bool fight(int attack,int defence,int monster_attack,int monster_defence);
extern int value_dice();


int main(){


	srand((int) time(0));

	character A;
	int a = 1;
	while(a%4==0){
		cout<<"your character level up"<<A.get_character_inital_attack()+1.5<<A.get_character_inital_defense()+1.5<<endl;
	}

	A.create_name();
	A.create_data();

	cout<<"Your name is "<<A.get_name()<<", your inital attack value is "<<A.get_character_inital_attack()<<", and your inital defense value is "<<A.get_character_inital_defense()<<"."<<endl;
	goblin B;


	B.level();

	cout<<"The first level monster you face have a defence value of "<<B.defence_value()<<", and it's attack value is "<<B.attack_value()<<"."<<endl;

	int result;
	int character_attack=A.get_character_inital_attack();
	int character_defense=A.get_character_inital_defense();
	int monster_attack=B.defence_value();
	int monster_defence=B.attack_value();
//result=fright(character_attack,character_defense,monster_attack,monster_defence);
a++; //add this line after the battle each time
A.update_main_character(); ////add this line after the battle each time
A.update_main_character(); ////add this line after the battle each time


if(fight(character_attack,character_defense,monster_attack,monster_defence)==0){
	return 0;
}
else{
	cout<<"";
}

B.level();

cout<<"The second level monster you face have a defence value of "<<B.defence_value()<<", and it's attack value is "<<B.attack_value()<<"."<<endl;


character_attack=A.get_character_inital_attack();
character_defense=A.get_character_inital_defense();
monster_attack=B.defence_value();
monster_defence=B.attack_value();
//result=fright(character_attack,character_defense,monster_attack,monster_defence);
a++; //add this line after the battle each time
A.update_main_character(); ////add this line after the battle each time
if(fight(character_attack,character_defense,monster_attack,monster_defence)==0){
	return 0;
}else{
	cout<<"";
}


B.level();

cout<<"The third level monster you face have a defence value of "<<B.defence_value()<<", and it's attack value is "<<B.attack_value()<<"."<<endl;


character_attack=A.get_character_inital_attack();
character_defense=A.get_character_inital_defense();
monster_attack=B.defence_value();
monster_defence=B.attack_value();
//result=fright(character_attack,character_defense,monster_attack,monster_defence);
a++; //add this line after the battle each time
A.update_main_character(); ////add this line after the battle each time
A.get_character_inital_defense()+1.5;
A.get_character_inital_attack()+1.5;

if(fight(character_attack,character_defense,monster_attack,monster_defence)==0){
	return 0;
}else{
	cout<<"";
}
cout<<"Your character LEVEL UP!"<<endl;

cout<<a<<endl;
king *C  = new king();
cout<<C->attack_value()<<endl;
cout<<C->defence_value()<<endl;

return 0;
}
