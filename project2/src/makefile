main: plane.o Runway.o main.o 
	g++ plane.o Runway.o main.o -o main.exe
plane.o: plane.hpp plane.cpp
	g++ plane.cpp -c -o plane.o
Runway.o: Runway.cpp Runway.cpp
	g++ Runway.cpp -c -o Runway.o
main.o: main.cpp Random.hpp
	g++ main.cpp -c -o main.o