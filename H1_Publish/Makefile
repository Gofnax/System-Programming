CC = gcc
OBJS = main.o general.o sudoku.o pictureLines.o
EXEC = prog
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -lm -o $@

main.o: main.c sudoku.h general.h
general.o: general.c general.h
sudoku.o: sudoku.c sudoku.h general.h
pictureLines.o: pictureLines.c pictureLines.h general.h

clean:
	rm -f $(OBJS) $(EXEC)