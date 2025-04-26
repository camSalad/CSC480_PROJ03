routing: main.o Router.o
	g++ -o routing -Wall -ansi -pedantic main.o Router.o

main.o: main.cpp Router.hpp
	g++ -c -Wall -ansi -pedantic main.cpp

Router.o: Router.cpp Router.hpp
	g++ -c -Wall -ansi -pedantic Router.cpp
