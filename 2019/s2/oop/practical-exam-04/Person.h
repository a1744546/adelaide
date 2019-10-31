#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;
class Person{

public: 
	Person();
    Person(string n,string o,int sl);
	void set_name(string n);
    void set_salary(int a);
    void set_personID(int b);
    string get_name();
    string get_occupation();
    virtual int get_salary();
    int get_personID();
    void set_occupation();

    ~Person();
protected:
    string name;
    string occupation;
    int salary;
    int serviceLength;
    int personID;
};
#endif
