#include <iostream>
#include <stdlib.h>
#include "Main.h"
#include <ctime>
//#include "monster.h"
//#include "npc.h"
using namespace std;
int value_dice()
{
  //srand((int) time (0));
  int dice = rand()%23;
  return dice;
}
bool result(int value_dice,int value_property,int lock_value)
{
if(value_dice+value_property>=lock_value)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool fright(int attack,int defence,int monster_attack,int monster_defence) // fright function
{
	if(attack<= monster_defence)
	{

	
		int dice = value_dice();
		if(result(dice,attack,monster_defence)==1)
		{
			int player_health = 100;
			int monster_health = 100;
			int total_attack = attack + dice;
			int lose_heath_player = monster_attack - defence;
			int lose_heath_monster = total_attack - monster_defence;
			cout<< "your dice value is"<<dice<<endl;
			while(player_health>=0 && monster_health >= 0)
			{
				player_health = player_health - lose_heath_player;
				monster_health = monster_health - lose_heath_monster;
			} 
			if(player_health>0 && monster_health <= 0)
			{
				cout<<"Although you attack is not enough,your dice got "<< dice <<",Congratulation on defeating the monster"<<endl;
				return true;
			}
			else
			{
				cout<<"Unfortunately,you lose"<<endl;
				return false;
			}
			
		}
		else // dice+attack < monster defence
		{
				
			cout<<"Unfortunately,your attack is less the monster`s defence and you arenot lucky enough,you lose"<<endl;
			return false;
		}
	}
	else // attack > monster defence
	{
		int player_health = 100;
		int monster_health = 100;
		int total_attack = attack;
		int lose_heath_player = monster_attack - defence;
		int lose_heath_monster = total_attack - monster_defence;
		while(player_health>=0 && monster_health >= 0)
		{
			player_health = player_health - lose_heath_player;
			monster_health = monster_health - lose_heath_monster;
		} 

				if(player_health>0 && monster_health <= 0)
				{
					cout<<"Congratulation on defeating the monster!"<<endl;
					return true;
				}
				else
				{
					cout<<"Unfortunately,you lose"<<endl;
					return false;
				}
	}
} 

