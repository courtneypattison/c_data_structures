#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

struct doubly_linked_list *create_doubly_linked_list()
{
    struct doubly_linked_list *list = malloc(sizeof *list);

    list->first = NULL;
    list->last = NULL;

    return list;
}
void delete_doubly_linked_list(struct doubly_linked_list *list)
{
    free(list);

    return;
}
