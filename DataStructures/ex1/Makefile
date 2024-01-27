CC = gcc
OBJS = q3.o q4.o q5.o q6.o q7.o main.o
EXEC = assignment1
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -lm -o $@

main.o: main.c q3.h q4.h q5.h q6.h q7.h
q3.o: q3.c q3.h
q4.o: q4.c q4.h
q5.o: q5.c q5.h
q6.o: q6.c q6.h
q7.o: q7.c q7.h

clean:
	rm -f $(OBJS) $(EXEC)