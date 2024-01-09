CC = gcc
OBJS = arrays.o exe.o lab2.o prog.o
EXEC = demo2
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra -Wconversion $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

arrays.o: arrays.c arrays.h
exe.o: exe.c arrays.h lab2.h exe.h
lab2.o: lab2.c lab2.h arrays.h
prog.o: prog.c exe.h

clean:
	rm -f $(OBJS) $(EXEC)