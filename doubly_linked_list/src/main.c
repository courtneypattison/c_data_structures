#include <stdio.h>
#include <stdlib.h>

#include "dl_list.h"

#define TEST_LEN 10

void print_int(void *data)
{
    printf("%d ", *((int*)data));

    return;
}

int compare_int(void *data1, void *data2)
{
    if (*((int*)data1) == *((int*)data2)) {
        return 1;
    } else {
        return 0;
    }
}

int main(void)
{
    int i, *j, k, *l;
    struct dl_list *list; 
    struct dl_node *node, *node1;

    printf("Doubly Linked List Test Suite\n"
           "=============================\n");

    printf("\ncreate_dl_list()\n"
             "----------------\n");
    list = create_dl_list();
    printf("actual:   N/A\n");
    printf("expected: N/A\n");

    printf("\ninsert_data_end()\n"
             "-----------------\n");
    for (i = 0; i < TEST_LEN; i++) {
        j = malloc(sizeof *j);
        *j = i;
        insert_data_end(list, j);
    }
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = 0; i < TEST_LEN; i++) {
        printf("%d ", i);
    }

    printf("\n\ninsert_data_beginning()\n"
               "-----------------------\n");
    j = malloc(sizeof *j);
    *j = -1;
    insert_data_beginning(list, j);
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i < TEST_LEN; i++) {
        printf("%d ", i);
    }

    printf("\n\ninsert_data_end()\n"
               "-----------------\n");
    j = malloc(sizeof *j);
    *j = 10;
    insert_data_end(list, j);
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i < TEST_LEN + 1; i++) {
        printf("%d ", i);
    }

    printf("\n\ntraverse_forward()\n"
               "------------------\n");
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i < TEST_LEN + 1; i++) {
        printf("%d ", i);
    }

    printf("\n\ntraverse_backward()\n"
               "-------------------\n");
    printf("actual:   ");
    traverse_backward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = TEST_LEN; i >= -1; i--) {
        printf("%d ", i);
    }

    printf("\n\nfind_from_backward()\n"
               "--------------------\n");
    k = 7;
    node = find_from_backward(list->last, &k, compare_int);
    printf("actual:   ");
    if (node) {
        print_int(node->data);
    }
    printf("\n");
    printf("expected: 7");

    printf("\n\nfind_from_forward()\n"
               "-------------------\n");
    k = 5;
    node = find_from_forward(list->first, &k, compare_int);
    if (node) {
        printf("actual:   ");
        print_int(node->data);
    }
    printf("\n");
    printf("expected: 5");

    printf("\n\ninsert_data_after()\n"
               "-------------------\n");
    l = malloc(sizeof *l);
    *l = 2;
    node1 = insert_data_after(list, node, l);
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("2 ");
    for (i = 6; i < TEST_LEN + 1; i++) {
        printf("%d ", i);
    }

    printf("\n\ninsert_data_before()\n"
               "-------------------\n");
    l = malloc(sizeof *l);
    *l = 2;
    node1 = insert_data_before(list, node, l);
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i < 5; i++) {
        printf("%d ", i);
    }
    printf("2 5 2 ");
    for (i = 6; i < TEST_LEN + 1; i++) {
        printf("%d ", i);
    }

    printf("\n\nremove_node()\n"
               "-------------------\n");
    free(node->data);
    remove_node(list, node);
    printf("actual:   ");
    traverse_forward(list, print_int);
    printf("\n");
    printf("expected: ");
    for (i = -1; i < 5; i++) {
        printf("%d ", i);
    }
    printf("2 2 ");
    for (i = 6; i < TEST_LEN + 1; i++) {
        printf("%d ", i);
    }

    traverse_forward(list, free);

    printf("\ncreate_dl_list()\n"
             "----------------\n");
    delete_dl_list(list);
    printf("actual:   N/A\n");
    printf("expected: N/A\n");

    return 0;
}
