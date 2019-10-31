#include "Team.h"
#include "person.h"
#include "Coach.h"
#include "Player.h"
#include <iostream>

Team::Team(){
team[0] = new Coach();
team[4] = new Coach();
team[1] = new Player();
team[2] = new Player();
team[3] = new Player();
	
	}

Person **Team::get_team(){
return team;
}
Team::~Team(){

}