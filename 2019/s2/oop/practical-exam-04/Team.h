#ifndef TEAM_H
#define TEAM_H
#include "person.h"
#include <string>
using namespace std;
class Team{
public:
 Team();
 person **get_team();
 ~Team();
private:
person *array[5];

};
#endif