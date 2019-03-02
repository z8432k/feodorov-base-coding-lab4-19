PROGRAM = calc

CFLAGS = -Wall -g -ansi -O0
LDLIBS = -lm

default: bin/$(PROGRAM)

bin/$(PROGRAM): bin/$(PROGRAM).o bin/error.o
	$(CC) $^ $(LDLIBS) -o $@

bin/error.o: src/error.c
	$(CC) $(CFLAGS) -o $@ -c $<

bin/$(PROGRAM).o: src/$(PROGRAM).c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv bin/*.o bin/$(PROGRAM)
