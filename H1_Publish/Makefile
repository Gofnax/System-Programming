CC = gcc
OBJS = q3.o  main.o
EXEC = assignment1
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -lm -o $@

main.o: main.c q3.h q4.h q5.h q6.h q7.h
q3.o: q3.c q3.h

clean:
	rm -f $(OBJS) $(EXEC)