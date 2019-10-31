#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "monster.h"
#include <ctime>
#include <cstdlib>
using namespace std;
 monster::monster(){
 	lev=0;
 	attack=0;
 	defense=0;
 }
 void monster::level(){
         
         lev++;
 }


int monster::defence_value(){
	
defense = rand()%(5)+lev;
  return defense;		
 }

 int monster::attack_value(){
//srand((int) time(0));
 attack = rand()%(5)+lev;
 return attack;

 }


monster::~monster(){

}
