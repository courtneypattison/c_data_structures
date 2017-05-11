#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static void exit_if_null(struct Node *node)
{
    if (node == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    return;
}


struct Node *create_list()
{
    struct Node *dummy_node;

    dummy_node = malloc(sizeof *dummy_node);
    exit_if_null(dummy_node);

	dummy_node->next = NULL;

	return dummy_node;
}


struct Node *init_node(void *data)
{
    struct Node *new_node;

    new_node = malloc(sizeof *new_node);
    exit_if_null(new_node);

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}


struct Node *add_front(struct Node *head, void *data)
{
    struct Node *front_node;

    exit_if_null(head);

    front_node = init_node(data);
    front_node->next = head->next;
    head->next = front_node;

    return front_node;
}

struct Node *add_back(struct Node *head, void *data)
{
    struct Node *back, *new;

    exit_if_null(head);

    back = get_back(head);
    new = init_node(data);
    back->next = new;

    return back;
}

struct Node *add_sorted(struct Node *head, void *data, int (*compare) (void *,
            void *))
{
    struct Node *sorted_node, *current;

    exit_if_null(head);

    if (head->next == NULL) {
        sorted_node = add_front(head, data);
        return sorted_node;
    }

    sorted_node = init_node(data);
    current = head;
    while (current->next != NULL && compare(data, current->next->data)) {
        current = current->next;
    }
    sorted_node->next = current->next;
    current->next = sorted_node;

    return sorted_node;
}


struct Node *get_front(struct Node *head)
{
    exit_if_null(head);

    return head->next;
}

struct Node *get_back(struct Node *head)
{
    struct Node *current;

    exit_if_null(head);

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}


struct Node *delete_front(struct Node *head)
{
    struct Node *front;

    exit_if_null(head);

    front = get_front(head);
    head->next = front->next;

    return front;
}


struct Node *delete_data(struct Node *head, void *data,
    int (*compare) (void *, void *))
{
    struct Node *current, *previous;

    previous = head;
    current = head->next;
    while (current != NULL && compare(data, current->data)) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;

    return current;
}


struct Node *find_data(struct Node *head, void *data,
    int (*compare) (void *, void *))
{
    struct Node *current;

    current = head->next;
    while (current != NULL && compare(data, current->data)) {
        current = current->next;
    }

    return current;
}


int get_length(struct Node *head)
{
    int length;
    struct Node *current;

    exit_if_null(head);

    length = 0;
    current = head->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}


void print_list(struct Node *head, void (*print) (void *))
{
    struct Node *current;

    exit_if_null(head);

    current = head->next;
    while (current != NULL) {
		print(current->data);
        current = current->next;
    }
    printf("\n");

    return;
}


void destroy_list(struct Node *head)
{
    struct Node *current, *front;

    exit_if_null(head);

    current = head->next;
    while (current != NULL) {
        front = delete_front(head);
        current = current->next;
        free(front);
    }
    free(head);

    return;
}

