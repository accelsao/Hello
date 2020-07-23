CC = g++

CFLAGS = -g -Wall -std=c++17

FILENAME = A

all: $(FILENAME).cpp
	$(CC) $(CFLAGS) -o $(FILENAME) $(FILENAME).cpp
	./$(FILENAME)
clean:
	$(RM) $(FILENAME)