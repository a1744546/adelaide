#include "king.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
king::king()
{
	array[0]=0;
	array[1]=0;
}
int king::defence_value()
{

 array[1]= rand()%(10);
 defense2 = array[1];
  return defense2;
}

int king::attack_value()
{
 
 array[0]= rand()%(10);
 attack2 = array[0];
 return attack2;
}