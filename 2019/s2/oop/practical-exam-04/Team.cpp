#include "Team.h"
#include "person.h"
#include <iostream>
Team::Team(){
	
	for (int i=0;i<5;i++){
		if(i==0||i==4){
			array[i]->set_name("coach");
		}
		
			array[i]->set_name("player");
	
	}
}
person **Team::get_team(){
return array;
}
Team::~Team(){
delete []array[5];
}