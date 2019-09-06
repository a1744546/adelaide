#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;
class person
{
	public:
    	person();
		person(string myName,int Salary); 
		void setName(string myName);      
		string getName();
		void setSalary(int mySalary);
		int getSalary();
		~person();
		string Name;
		int salary;
};

#endif