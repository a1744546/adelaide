#include "Person.h"
using namespace std;
Person::Person(){
name = null;
occupation = null;
salary = 0;
serviceLength = 0;
}
Person::Person(string n,string o,int s1){
	name = n;
	occupation = o;
	salary=0;
	serviceLength =s1;
}
void Person::set_name(string n){
	name = n;
}
void Person::set_salary(int a){
	salary = a;
}
void Person::set_personID(int b){
	personID = b;
}
string Person::get_name(){
	return name;
}
string Person::get_occupation(){
	return occupation;
}
int Person::get_salary(){
	return salary;
}
int Person::get_personID(){
	return personID;
}
Person::~Person(){

}
