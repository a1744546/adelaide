all:main
main: character.o fright.o Main.o monster.o
	g++ main-1.cpp character.o fright.o Main.o monster.o -o main

character.o: character.cpp character.h 
	g++  -c character.cpp -o character.o

fright.o: fright.cpp 
	g++  -c fright.cpp -o fright.o

Main.o: Main.cpp Main.h
	g++ -c Main.cpp -o Main.o

monster.o: monster.cpp monster.h
	g++ -c monster.cpp -o monster.o

clean:
	rm  -f  *.o  driver
