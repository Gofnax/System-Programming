CC = gcc
OBJS = lab1.o main.o
EXEC = demo
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra -Wconversion

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

lab1.o: lab1.c lab1.h
main.o: main.c lab1.h

clean:
	rm -f $(OBJS) $(EXEC)