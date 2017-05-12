#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Stack *create_stack()
{
    struct Stack *stack;

    stack = malloc(sizeof *stack);
    if (stack == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    stack->list = create_list();
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void destroy_stack(struct Stack *stack)
{
    destroy_list(stack->list);
    free(stack);

    return;
}

void push(struct Stack *stack, void *data)
{
    stack->top = add_front(stack->list, data);
    stack->size++;

    return;
}

struct Node *pop(struct Stack *stack)
{
    struct Node *popped;

    if (stack->size > 0) {
        popped = delete_front(stack->list);
        stack->top = get_front(stack->list);
        stack->size--;
        return popped;
    } else {
        destroy_stack(stack);
        fprintf(stderr, "You can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}

void *peek(struct Stack *stack)
{
    if (stack->size > 0) {
        return stack->top->data;
    } else {
        destroy_stack(stack);
        fprintf(stderr, "You can't peek at an empty stack\n");
        exit(EXIT_FAILURE);
    }
}
