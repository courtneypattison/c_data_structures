objdir = obj/

program = dl_list

sources = main.c dl_list.c

objects = $(patsubst %.c,$(objdir)%.o,$(sources))

CFLAGS = -Wall -ansi -Iinclude -pedantic -g
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
