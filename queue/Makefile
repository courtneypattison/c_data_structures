program = queue
objects = main.o list.o queue.o

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
VPATH = include:src

$(program) : $(objects)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objects) : list.h
queue.o : queue.h

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
