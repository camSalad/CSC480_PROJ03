vect: vectoring.o
	g++ -o vect -Wall -ansi -pedantic vectoring.o

vectoring.o: vectoring.cpp
	g++ -c -Wall -ansi -pedantic vectoring.cpp

