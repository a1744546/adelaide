#ifndef KING_H
#define KING_H	
#include <iostream>
#include <stdlib.h>
#include "monster.h"
using namespace std;
class king : public monster{
		public:
		int array[2];
		int attack2;
		int defense2;
		king();
		int defence_value();
		int attack_value();
};
#endif	
