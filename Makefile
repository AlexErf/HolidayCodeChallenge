
CC=g++

all: holidaycode.exe

holidaycode.exe: holidaycode.o day1.o
	$(CC) $^ -o $@
	rm $^

holidaycode.o: holidaycode.cpp
	$(CC) -c $^

day1.o: days/day1.cpp
	$(CC) -c $^

clean:
	rm *.o *.exe

