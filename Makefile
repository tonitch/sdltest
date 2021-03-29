CC=g++

CFLAGS= -Wall -g
LDLIBS= -lSDL2  -lSDL2_image -lm

all: main

main: main.cpp GameWindow.cpp GameWindow.hpp 
	$(CC) $(CFLAGS) -o main main.cpp GameWindow.cpp $(LDLIBS)

clean: 
	$(RM) main *.o *~

run: main
	./main

.PHONY: all clean run
