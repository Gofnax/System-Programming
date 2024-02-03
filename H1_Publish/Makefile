CC = gcc
OBJS = main.o general.o sudoku.o pictureLines.o pictureManipulation.o
EXEC = prog
DEBUG = -g
CFLAGS = -Wall -Werror -Wextra $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -lm -o $@

general.o: general.c general.h
main.o: main.c sudoku.h general.h pictureLines.h pictureManipulation.h
pictureLines.o: pictureLines.c pictureLines.h general.h
pictureManipulation.o: pictureManipulation.c pictureManipulation.h general.h
sudoku.o: sudoku.c sudoku.h general.h


clean:
	rm -f $(OBJS) $(EXEC)