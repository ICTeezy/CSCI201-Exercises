FILES = main.cpp Beverage.cpp

build: main.cpp Beverage.cpp
	@g++ $(FILES) -o out

Beverage.cpp: Beverage.h
	@g++ Beverage.cpp -c 

clean:
	@rm -f *.o out