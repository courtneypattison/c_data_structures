#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "queue.h"

struct Queue *create_queue()
{
    struct Queue *queue;

    queue = malloc(sizeof *queue);
    if (queue == NULL) {
        fprintf(stderr, "Null pointer\n");
        exit(EXIT_FAILURE);
    }

    queue->list = create_list();

    return queue;
}

void destroy_queue(struct Queue *queue)
{
    destroy_list(queue->list);
    free(queue);

    return;
}

void add_to_queue(struct Queue *queue, void *data)
{
    add_back(queue->list, data);

    return;
}

struct Node *remove_from_queue(struct Queue *queue)
{
    struct Node *removed;

    removed = delete_front(queue->list);

    return removed;
}

int is_queue_empty(struct Queue *queue)
{
    if (queue->list->next == NULL) {
        return 1;
    } else {
        return 0;
    }
}

struct Node *peek_front_queue(struct Queue *queue)
{
    if (is_queue_empty(queue)) {
        return NULL;
    } else {
        return get_front(queue->list);
    }
}
