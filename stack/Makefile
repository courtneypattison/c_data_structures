program = stack
objects = main.o list.o stack.o

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
VPATH = include:src

$(program) : $(objects)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objects) : list.h
stack.o : stack.h

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
