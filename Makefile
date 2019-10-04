CFLAGS   = -O -g -Wall -fPIC -ansi -lm

all: c2

c2: c2.c c2.h
	g++ c2.c $(CFLAGS) -o c2
clean:
	rm -rf *~ *.o c2 *tmpdatafile*
