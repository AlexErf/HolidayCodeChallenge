
CC=g++

all: holidaycode.exe

holidaycode.exe: holidaycode.cpp
	$(CC) $^ -o $@

clean:
	rm *.exe

