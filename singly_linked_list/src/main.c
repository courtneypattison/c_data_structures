#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void print_test(int boolean);
void print_int(void *data);

int main(void)
{
    int i;
    int array_length, list_length;
    int array[3];
    int data;
    struct Node *head, *new_node, *front;

    /* Array of test data */
    array_length = 3;
    for (i = 0; i < array_length; i++) {
        array[i] = i * 5; 
    }

    /* The following tests verify the functionality of the linked list by */
    /* testing positive, negative, zero, and NULL values. Extremely large and */
    /* small numbers are not tested as input values due to the scope of this lab. */
     

    head = create_list();
    print_test(head->next == NULL);
    printf("expected: NULL, actual: %p\n", (void *)head->next);

    data = 0;
    new_node = init_node(&data);
    print_test(*((int *)new_node->data) == data);
    printf("expected: %d, actual: %d\n", data, *((int *)new_node->data));
    free(new_node);

    data = -1;
    new_node = init_node(&data);
    print_test(*((int *)new_node->data) == data);
    printf("expected: %d, actual: %d\n", data, *((int *)new_node->data));
    free(new_node);

    data = 1000000000;
    new_node = init_node(&data);
    print_test(*((int *)new_node->data) == data);
    printf("expected: %d, actual: %d\n", data, *((int *)new_node->data));
    free(new_node);

    for (i = 0; i < array_length; i++) {
        add_front(head, &array[i]);
        print_list(head, print_int);
    }
    list_length = get_length(head);
    print_test(list_length == 3);
    printf("expected: 3, actual: %d\n", list_length);

    front = get_front(head);
    print_test(*((int *)front->data) == 10);
    printf("expected: 10, actual: %d\n", *((int *)front->data));


    front = delete_front(head);
    print_test(*((int *)front->data) == 10);
    printf("expected: 10, actual: %d\n", *((int *)front->data));
    free(front);

    front = get_front(head);
    print_test(*((int *)front->data) == 5);
    printf("expected: 5, actual: %d\n", *((int *)front->data));

    list_length = get_length(head);
    print_test(list_length == 2);
    printf("expected: 2, actual: %d\n", list_length);

    destroy_list(head);

    head = NULL;

    /* Uncommenting any of the following lines will result in an exit failure */
    /* add_front(head, 100); */
    /* front = get_front(head); */
    /* front = delete_front(head); */
    /* list_length = get_length(head); */
    /* print_list(head); */
    /* destroy_list(head); */

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

void print_int(void *data)
{
    printf("%d ", *((int *)data));

    return;
}

