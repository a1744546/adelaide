#include "Team.h"
#include "person.h"
#include "Coach.h"
#include "Player.h"
#include <iostream>
Team::Team(){
	
array[0] = new Coach();
array[4] = new Coach();
array[1] = new Player();
array[2] = new Player();
array[3] = new Player();
}
person **Team::get_team(){
return array;
}
Team::~Team(){
delete []array[5];
}