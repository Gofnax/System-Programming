CC = gcc
OBJS = main.o employee.o
EXEC = demo8b
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c employee.h
employee.o: employee.c employee.h

clean:
	rm -f $(OBJS) $(EXEC)