all: main.o MallardDuck.o WildTurkey.o TurkeyAdapter.o Duck.o
	g++ main.o MallardDuck.o WildTurkey.o TurkeyAdapter.o Duck.o -o main.bin

main.o: main.cpp
	g++ -c main.cpp -o main.o

MallardDuck.o: MallardDuck.h Duck.h
