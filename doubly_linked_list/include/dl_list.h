#ifndef __DL_LIST__
#define __DL_LIST__

struct dl_node {
    void *data;
    struct dl_node *prev;
    struct dl_node *next;
};

struct dl_list {
    struct dl_node *first;
    struct dl_node *last;
};

/* allocates memory for the list */
struct dl_list *create_dl_list();

/* deallocates memory for list and any nodes in list */
void delete_dl_list(struct dl_list *list);

/* iterates through the data in the list from head to tail */
void traverse_forward(struct dl_list *list, void (*func) (void *));

/* iterates through the data in the list from tail to head */
void traverse_backward(struct dl_list *list, void (*func) (void *));

/* finds node in list using compare function on data from head to tail */
struct dl_node *find_from_forward(struct dl_node *start_node, void *data,
        int (*compare) (void *, void *));

/* finds node in list using compare function on data from tail to head */
struct dl_node *find_from_backward(struct dl_node *start_node, void *data,
        int (*compare) (void *, void *));

/* creates node and inserts data after specified node */
struct dl_node *insert_data_after(struct dl_list *list, struct dl_node *node,
        void *data);

/* creates node and inserts data before specified node */
struct dl_node *insert_data_before(struct dl_list *list, struct dl_node *node,
        void *data);

/* adds data to the head of the list */
struct dl_node *insert_data_beginning(struct dl_list *list, void *data);

/* adds data to the tail of the list */
struct dl_node *insert_data_end(struct dl_list *list, void *data);

/* removes node from list */
void remove_node(struct dl_list *list, struct dl_node *node);

#endif
