CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -g
LDFLAGS=

SOURCES=$(wildcard *.c )
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=exec

all: $(EXECUTABLE)
	./$(EXECUTABLE)

debug: $(SOURCES)
	$(CC) $(CFLAGS) -ggdb $< -o debug
	gdb ./debug

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS) debug
