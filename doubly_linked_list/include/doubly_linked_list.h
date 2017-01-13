#ifndef __DOUBLY_LINKED_LIST__
#define __DOUBLY_LINKED_LIST__

struct doubly_linked_node {
    void *data;
    struct doubly_linked_node *prev;
    struct doubly_linked_node *next;
};

struct doubly_linked_list {
    struct doubly_linked_node *first;
    struct doubly_linked_node *last;
};

struct doubly_linked_list *create_doubly_linked_list();

void delete_doubly_linked_list(struct doubly_linked_list *list);

#endif
