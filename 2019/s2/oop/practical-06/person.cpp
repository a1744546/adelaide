#include<iostream>
#include<string>
#include"person.h"
person::person(){
	Name;
	salary;
}

person::person(string myName,int Salary){
	Name=myName;
	salary=Salary;

}
void person::setName(string myName){
	Name=myName;
}
string person::getName(){
	return Name;
}
void person::setSalary(int mySalary){
	salary=mySalary;

}
int person::getSalary(){
	return salary;
}
person::~person()
{

}