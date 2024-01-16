CC = gcc
OBJS = arrays.o exe.o lab3.o main.o
EXEC = demo3
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

arrays.o: arrays.c arrays.h
exe.o: exe.c exe.h lab3.h
lab3.o: lab3.c lab3.h
main.o:main.c exe.h

clean:
	rm -f $(OBJS) $(EXEC)