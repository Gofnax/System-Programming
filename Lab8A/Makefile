CC = gcc
OBJS = main.o
EXEC = demo3
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c 

clean:
	rm -f $(OBJS) $(EXEC)