#include "Person.h"
Person::Person(string n, string o, int sl){
name = n;
occupation = o;
serviceLength =sl;
salary =0;
}   // creates a person of name n, occupation o, and service length sl
Person::Person(){
	name = "";
occupation = "";
serviceLength =0;
salary =0;
}
Person::~Person(){
}
void Person::set_name(string n)
{
name = n;
}
string Person::get_name(){
return name;
}

void Person::set_occupation(string o){
occupation = o;
}
string Person::get_occupation(){
return occupation;
}

void Person::set_salary(int s){
salary = s;
}
int Person::get_salary(){
return salary;
}

