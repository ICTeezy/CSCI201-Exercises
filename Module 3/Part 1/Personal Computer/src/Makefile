FILES = main.cpp PersonalComputer.cpp

build: $(FILES)
	@g++ -o out $(FILES)

PersonalComputer.cpp: PersonalComputer.h
	@g++ -c PersonalComputer.cpp

run: build
	@./out

clean:
	@rm -f *.o out