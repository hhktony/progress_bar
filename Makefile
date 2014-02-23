CC = gcc
CFLAGS = -I. -Wall
LDFLAGS = -lm
exe = test

test: test.o progress_bar.o
	$(CC) progress_bar.o test.o -o $@ $(LDFLAGS)

test.o: test.c
	$(CC) -c $(CFLAGS) test.c

progress_bar.o: progress_bar.h progress_bar.c
	$(CC) -c $(CFLAGS) progress_bar.c

.PHONY: clean test

clean:
	$(RM) *.o a.out *~ tags $(exe)
