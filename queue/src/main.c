#include <stdio.h>

#include "queue.h"

int get_int(struct Node *node);

void print_test(int boolean);

int main(void)
{
    struct Queue *queue = NULL;
    int data;

    printf("create_queue()\n"
           "------------\n");
    queue = create_queue();
    print_test(queue != NULL);
    printf("\n");

    data = 0;
    printf("\nadd_to_queue(queue, %d)\n"
             "------------\n", data);
    add_to_queue(queue, &data);
    print_test(get_int(peek_front_queue(queue)) == data);
    printf("expected: %d\tactual: %d\n", data, get_int(peek_front_queue(queue)));

    printf("\nremove_from_queue(queue)\n"
             "-----------------\n");
    remove_from_queue(queue);
    print_test(is_queue_empty(queue) == 1);
    printf("expected: %d\tactual: %d\n", 1, is_queue_empty(queue));

    printf("\nis_queue_empty(queue)\n"
             "--------------\n");
    add_to_queue(queue, &data);
    print_test(is_queue_empty(queue) == 0);
    printf("expected: %d\tactual: %d\n", 0, is_queue_empty(queue));

    printf("\npeek_front_queue(queue)\n"
             "--------------\n");
    print_test(get_int(peek_front_queue(queue)) == data);
    printf("expected: %d\tactual: %d\n", data, get_int(peek_front_queue(queue)));

    printf("\ndestroy_queue(queue)\n"
             "-------------\n");
    destroy_queue(queue);

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

int get_int(struct Node *node)
{
    return *((int *)node->data);
}
