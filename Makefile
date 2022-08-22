CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic
LDFLAGS=

SOURCES=$(wildcard *.c )
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(EXECUTABLE)
	./$(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS) -ggdb -fvar-tracking $< -o debug
	gdb ./debug core

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECUTABLE) *.o debug
