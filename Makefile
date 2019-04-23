main: Window.o Ball.o Lift.o main.cpp
	g++ -std=c++11 Window.o Ball.o Lift.o main.cpp -lncurses -pthread

Window.o: Window.cpp Window.h
	g++ -c Window.cpp -std=c++11 -lncurses

Ball.o: Ball.cpp Ball.h
	g++ -c Ball.cpp -std=c++11 -lncurses


Lift.o: Lift.cpp Lift.h
	g++ -c Lift.cpp -std=c++11 -lncurses

clean:
	rm -f *.o test
