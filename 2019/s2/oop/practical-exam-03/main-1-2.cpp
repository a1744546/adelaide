#include <iostream>
using namespace std;
#include "Team.h"
#include "Player.h"
int main(){
Player A;
Player B;
Player C;
    cout << A.get_jersey_number()<< endl;
	cout << A.get_name() << endl;
	
	cout<< add_player(A,B)<<endl;
	return 0;
}