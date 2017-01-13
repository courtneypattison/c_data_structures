objdir = obj/

program = doubly_linked_list

sources = main.c doubly_linked_list.c

objects = $(patsubst %.c,$(objdir)%.o,$(sources))

CFLAGS = -Wall -std=c99 -Iinclude -pedantic -g
VPATH = include:src

all : $(program)

$(program) : $(objects)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $(program) $(objects)

$(objdir)%.o : %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean
clean :
	-@$(RM) $(program) $(objects)
