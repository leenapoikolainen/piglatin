piglatin: main.o piglatin.o
	g++ -Wall -g main.o piglatin.o -o piglatin

main.o: main.cpp piglatin.h
	g++ -Wall -g -c main.cpp

piglatin.o: piglatin.cpp piglatin.h
	g++ -Wall -g -c piglatin.cpp
