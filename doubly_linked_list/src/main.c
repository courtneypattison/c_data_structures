#include "doubly_linked_list.h"

int main(void)
{
    struct doubly_linked_list *list = create_doubly_linked_list();
    delete_doubly_linked_list(list);

    return 0;
}
