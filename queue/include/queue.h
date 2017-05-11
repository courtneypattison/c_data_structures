/*
 * Courtney Bodi
 * 0687517
 */

#ifndef __QUEUE__
#define __QUEUE__

#include "list.h"

struct Queue {
    struct Node *list;
};

/*
 * Preconditions: none
 * Postconditions: an initialized queue
 */
struct Queue *create_queue();

/*
 * Preconditions: an initialized queue
 * Postconditions: the queue is freed from memory
 */
void destroy_queue(struct Queue *queue);

/*
 * Preconditions: an initialized queue
 * Postconditions: data is added to the back of the queue
 */
void add_to_queue(struct Queue *queue, void *data);

/*
 * Preconditions: a nonempty queue
 * Postconditions: the front node is removed from the queue, the queue is
 * one node shorter
 */
struct Node *remove_from_queue(struct Queue *queue);

/*
 * Preconditions: an initialized queue
 * Postconditions: 1 or 0 is returned if the queue is empty or contains nodes
 * respectively
 */
int is_queue_empty(struct Queue *queue);

/*
 * Preconditions: an initialized nonempty queue
 * Postconditions: a pointer to the node in the front of the queue is returned
 */
struct Node *peek_front_queue(struct Queue *queue);

#endif
