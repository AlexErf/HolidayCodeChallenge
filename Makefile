
CC=g++
FLAGS= --std=c++11

all: holidaycode.exe

holidaycode.exe: holidaycode.o day1.o day2.o day3.o day4.o
	$(CC) $^ $(FLAGS) -o $@
	rm $^

holidaycode.o: holidaycode.cpp
	$(CC) $(FLAGS) -c $^

day1.o: days/day1.cpp
	$(CC) $(FLAGS) -c $^

day2.o: days/day2.cpp
	$(CC) $(FLAGS) -c $^

day3.o: days/day3.cpp
	$(CC) $(FLAGS) -c $^

day4.o: days/day4.cpp
	$(CC) $(FLAGS) -c $^

clean:
	rm *.exe

