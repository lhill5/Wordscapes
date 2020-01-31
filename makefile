wordscapes: wordscapes.c linkedList.c hash.c
	gcc wordscapes.c linkedList.c hash.c -o word -g -Wall
run:
	./word
gdb:
	gdb ./word
clean:
	rm word
