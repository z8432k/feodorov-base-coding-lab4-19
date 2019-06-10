CC = g++
PROGRAM = calc
CFLAGS = -Wall -Wextra -ggdb -std=c++14 -O0
LDLIBS = -lm

default: bin/$(PROGRAM)

bin/$(PROGRAM): bin/$(PROGRAM).o
	$(CC) $^ $(LDLIBS) -o $@

bin/$(PROGRAM).o: src/$(PROGRAM).cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv bin/*.o bin/$(PROGRAM)
