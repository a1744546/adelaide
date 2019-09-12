#include <iostream>
#include "Player.h"
using namespace std;
int main(){

Player A;
	cout << A.get_jersey_number()<< endl;
	cout << A.get_name() << endl;

	Player* B = new Player(5,"test");
	cout << B->get_jersey_number()<< endl;
	cout << B->get_name() << endl;
delete[] B;
return 0;

}