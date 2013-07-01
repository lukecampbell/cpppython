CC=g++
CFLAGS=-g -ggdb -Wall -Iinclude
LDFLAGS= -lm
OBJECTS=src/test.o

all: src/test

src/test: $(OBJECTS)
	$(CC) -o $@ $(LDFLAGS) $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf src/*.o
	rm -rf src/test
