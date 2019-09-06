#include <iostream>
#include "person.h"
#include <string>
using namespace std;
int main()
{
	person A, B, C, D;	
	A.setName("Wei");
	A.setSalary(19);	
	B.setName("Timi");
	B.setSalary(10);	
	C.setName("Kiven");
	C.setSalary(50);
	D.setName("Jone");
	D.setSalary(19);	
	cout << "Person: "<<A.getName()<<" has salary "<<A.getSalary()<<endl;
	cout << "Person: "<<B.getName()<<" has salary "<<B.getSalary()<<endl;
	cout << "Person: "<<C.getName()<<" has salary "<<C.getSalary()<<endl;
	cout << "Person: "<<D.getName()<<" has salary "<<D.getSalary()<<endl;
	return 0;

}