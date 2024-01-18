CC = gcc
OBJS = q3.o main.o q4.o
EXEC = assignment1
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c q3.h q4.h
q3.o: q3.c q3.h
q4.o: q4.c q4.h

clean:
	rm -f $(OBJS) $(EXEC)