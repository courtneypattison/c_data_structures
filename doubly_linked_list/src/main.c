#include <stdio.h>
#include <stdlib.h>

#include "dl_list.h"

#define TEST_LEN 10

void print_int(void *data)
{
    printf("%d\n", *((int*)data));

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
    struct dl_list *list = create_dl_list();
    struct dl_node *node, *node1;

    for (i = 0; i < TEST_LEN; i++) {
        j = malloc(sizeof *j);
        *j = i;
        insert_data_end(list, j);
        /* insert_data_beginning(list, j); */
    }
    /* traverse_forward(list, print_int); */
    /* traverse_backward(list, print_int); */

    k = 7;
    /* node = find_from_forward(list->first, &k, compare_int); */
    node = find_from_backward(list->last, &k, compare_int);
    if (node) {
        print_int(node->data);
    }
    l = malloc(sizeof *l);
    *l = 2;
    node1 = insert_data_after(list, node, l);
    traverse_forward(list, print_int);

    traverse_forward(list, free);
    delete_dl_list(list);

    return 0;
}
