#ifndef TEAM_H
#define TEAM_H
#include "Person.h"
using namespace std;
class Team{
public:
 Team();
 Person **get_team();
 ~Team();
protected:
Person *team[5];
};
#endif