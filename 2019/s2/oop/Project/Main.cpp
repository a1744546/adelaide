#include "Main.h"	
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void Main::value_bout()
{
	bout = 0;

}
int Main::current_value_bout()
{
	bout++;
	return bout;
}


bool Main::choose(std::string choice)
{
return true;
}
bool Main::lucky_box(int bout)
{
	srand((int) time (0));
  if(rand()%100+bout>50)
  {
return true;
  }
}
