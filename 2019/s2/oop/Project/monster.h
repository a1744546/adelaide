#ifndef MONSTER_H
#define MONSTER_H
class monster{
	public: 
		monster();
		void level();
		virtual int defence_value();

		virtual int attack_value();

		 
         ~monster();
     public:
int lev;
int attack;
int defense;

};

#endif