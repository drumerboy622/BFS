make: wrestler.c
	gcc -g -Wall -std=c99 -o wrestler wrestler.c

clean:
	rm wrestler
