#include <stdio.h>
#include <stdlib.h>

#include "dl_list.h"

struct dl_list *create_dl_list()
{
    struct dl_list *list = malloc(sizeof *list);

    list->first = NULL;
    list->last = NULL;

    return list;
}


void delete_dl_list(struct dl_list *list)
{
    struct dl_node *node = list->first, *temp;

    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    free(list);

    return;
}


static struct dl_node *initialize_node(void *data)
{
    struct dl_node *new_node = malloc(sizeof *new_node);

    if (new_node) {
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = NULL;
    }

    return new_node;
}


void traverse_forward(struct dl_list *list, void (*func) (void *))
{
    struct dl_node *node = list->first;

    while (node) {
        func(node->data);
        node = node->next;
    }

    return;
}


void traverse_backward(struct dl_list *list, void (*func) (void *))
{
    struct dl_node *node = list->last;

    while (node) {
        func(node->data);
        node = node->prev;
    }

    return;
}


struct dl_node *find_from_forward(struct dl_node *node,
        void *data, int (*compare) (void *, void *))
{
    while (node) {
        if (compare(data, node->data)) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}


struct dl_node *find_from_backward(struct dl_node *node, void *data,
        int (*compare) (void *, void *))
{
    while (node) {
        if (compare(data, node->data)) {
            return node;
        }
        node = node->prev;
    }

    return NULL;
}


static void insert_node_after(struct dl_list *list, struct dl_node *node,
        struct dl_node *new_node)
{
    new_node->prev = node;
    if (node->next == NULL) {
        list->last = new_node;
    } else {
        new_node->next = node->next;
        node->next->prev = new_node;
    }
    node->next = new_node;

    return;
}


struct dl_node *insert_data_after(struct dl_list *list, struct dl_node *node,
        void *data)
{
    struct dl_node *new_node = initialize_node(data);
    insert_node_after(list, node, new_node);

    return new_node;
}


static void insert_node_before(struct dl_list *list, struct dl_node *node,
        struct dl_node *new_node)
{
    new_node->next = node;
    if (node->prev == NULL) {
        list->first = new_node;
    } else {
        new_node->prev = node->prev;
        node->prev->next = new_node;
    }
    node->prev = new_node;

    return;
}


struct dl_node *insert_data_before(struct dl_list *list, struct dl_node *node,
        void *data)
{
    struct dl_node *new_node = initialize_node(data);
    insert_node_before(list, node, new_node);

    return new_node;
}


static void insert_node_beginning(struct dl_list *list,
        struct dl_node *new_node)
{
    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        insert_node_before(list, list->first, new_node);
    }

    return;
}


struct dl_node *insert_data_beginning(struct dl_list *list, void *data)
{
    struct dl_node *new_node = initialize_node(data);
    insert_node_beginning(list, new_node);
    
    return new_node;
}


static void insert_node_end(struct dl_list *list, struct dl_node *new_node)
{
    if (list->last == NULL) {
        insert_node_beginning(list, new_node);
    } else {
        insert_node_after(list, list->last, new_node);
    }

    return;
}


struct dl_node *insert_data_end(struct dl_list *list, void *data)
{
    struct dl_node *new_node = initialize_node(data);
    insert_node_end(list, new_node);
    
    return new_node;
}


void remove_node(struct dl_list *list, struct dl_node *node)
{
    if (node->prev == NULL) {
        list->first = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next == NULL) {
        list->last = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    free(node);

    return;
}

