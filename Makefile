CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
LDFLAGS=

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
EXECUTABLE=exec

all: $(EXECUTABLE)
	./$(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS) -ggdb -fvar-tracking $< -o debug
	gdb ./debug core

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECUTABLE) *.o debug
