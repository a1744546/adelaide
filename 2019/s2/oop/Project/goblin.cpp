#include "goblin.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int goblin::defence_value()
{
defense1 = rand()%(5)+lev;
  return defense1;
}

int goblin::attack_value()
{
 attack1 = rand()%(5)+lev;
 return attack1;
}

