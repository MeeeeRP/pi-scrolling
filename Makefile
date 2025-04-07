INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: scroll
scroll: main.o letters.o
	cc -o scroll main.o letters.o $(LDFLAGS)

clean:
	rm -f *.o scroll
main.o: main.c letters.h
	cc -c main.c -I ~/include
display.o: letters.c letters.h
	cc -c letters.c -I ~/include
run: scroll
	./scroll
