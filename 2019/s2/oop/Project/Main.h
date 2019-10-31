
#ifndef MAIN_H
#define MAIN_H	
#include <iostream>
#include <stdlib.h>
using namespace std;
class team{
	public:
		int dice;
		int bout;
		void value_bout(); 
		int current_value_bout();                    // record the times of battle
		
		bool result(int value_dice,int value_property,int lock_value);
		bool choose(std::string choice);
		bool lucky_box(int bout);
};
#endif
