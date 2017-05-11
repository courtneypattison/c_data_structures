program = hash_table
objects = main.o list.o hash_table.o phone_dir.o

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
VPATH = include:src

$(program) : $(objects)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objects) : list.h hash_table.h phone_dir.h

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
