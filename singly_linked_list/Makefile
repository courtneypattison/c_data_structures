
program = list
objects = main.o list.o

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
VPATH = include:src

$(program) : $(objects)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objects) : list.h

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
