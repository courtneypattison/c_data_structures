#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "math.h"
#include "stack.h"

struct Coordinate {
    int row;
    int col;
};

void print_test(int boolean);

struct Coordinate get_coordinate(struct Node *node);

int main(void)
{
    struct Stack *stack;
    struct Coordinate test_push, test_peek;
    struct Node *test_pop;
    int i;

    printf("Stack Testing\n"
           "=============\n");

    printf("\ncreate_stack()\n"
             "-------------\n");
    stack = create_stack();
    /* Uncommenting commented code will result in expected stack error messages*/
    /* print_list(stack->list); */
    print_test(stack->top == NULL);
    printf("stack->top\texpected: NULL, actual: %p\n", (void *)stack->top);
    print_test(stack->size == 0);
    printf("stack->size\texpected: 0, actual: %d\n", stack->size);

    printf("\npush()\n"
             "------\n");
    for (i = 0; i > -3; i--) {
        test_push.row = i;
        push(stack, &test_push);
        test_peek = *((struct Coordinate *)peek(stack));
        print_test(test_push.row == test_peek.row);
        printf("test_push.row\texpected: %d, actual: %d\n", i, test_peek.row);
    }

    printf("\npop()\n"
             "-----\n");
    for (i = -3; i < 0; i++) {
        test_peek = *((struct Coordinate *)peek(stack));
        test_pop = pop(stack);
        print_test(get_coordinate(test_pop).row == test_peek.row);
        printf("test_pop->coordinate.row\texpected: %d, actual: %d\n",
            i + 1, get_coordinate(test_pop).row);
        free(test_pop);

        /* test_peek = peek(stack); */
        /* print_test(stack->top->coordinate.row == test_peek.row); */
        /* printf("stack->top->coordinate.row\texpected: %d, actual: %d\n", */
        /*     i + 1, test_pop->coordinate.row); */

        print_test(stack->size == abs(i + 1));
        printf("stack->size\t\texpected: %d, actual: %d\n",
            abs(i + 1), stack->size);
    }

    printf("\npeek()\n"
             "------\n");
    for (i = 10000; i < 1000000000; i *= 100) {
        test_push.row = i;
        push(stack, &test_push);
        test_peek = *((struct Coordinate *)peek(stack));
        print_test(test_peek.row == test_push.row);
        printf("test_peek.row\texpected: %d, actual: %d\n", i, test_peek.row);
    }

    printf("\ndestroy_stack()\n"
             "--------------\n");
    destroy_stack(stack);

    return 0;
}

void print_test(int boolean) {
    if (boolean == 1) {
        printf("PASS\t");
    } else {
        printf("FAIL\t");
    }

    return;
}

struct Coordinate get_coordinate(struct Node *node)
{
    return *((struct Coordinate *)(node->data));
}
