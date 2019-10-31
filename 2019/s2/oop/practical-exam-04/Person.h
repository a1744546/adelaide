#ifndef PERSON_H
#define PERSON_H
using namespace std;
class Person{
public:
Person(string n, string o, int sl);  // creates a person of name n, occupation o, and service length sl
Person();
~Person();
void set_name(string n);
string get_name();

void set_occupation(string o);
string get_occupation();

void set_salary(int s);
virtual int get_salary();

void set_personID();
int get_personID();

private:
 string name;                       // the name of a person
 string occupation;                 // the occupation of a person
 
 int salary;                        // the salary of a person; takes only non-negative values
 int serviceLength;                   // the service length of a person
 int personID;                        // the unique ID of a person

};
#endif;
