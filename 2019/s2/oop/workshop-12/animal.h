#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;
class animal
{ 
	
		int v;
		std::string n;
		public:
		int animalID ;            // the animal's unique ID
		int volume;               // the volume of the animal's body
		string name;              // the animal's name
		animal();
		animal(string n, int v);   // creates an animal with name n and body volume v.
        	                        // animals are allocated a unique ID on creation
		
		
		string set_name();
		virtual get_name();
		int set_ID();
		int get_ID();
		int set_volume();
		int get_volume();



};
#endif