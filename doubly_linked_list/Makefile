program = dl_list
objects = main.o dl_list.o

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
VPATH = include:src

$(program) : $(objects)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objects) : dl_list.h

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
