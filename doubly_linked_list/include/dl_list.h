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

struct dl_list *create_dl_list();

void delete_dl_list(struct dl_list *list);

void traverse_forward(struct dl_list *list, void (*func) (void *));

void traverse_backward(struct dl_list *list, void (*func) (void *));

struct dl_node *find_from_forward(struct dl_node *start_node, void *data,
        int (*compare) (void *, void *));

struct dl_node *find_from_backward(struct dl_node *start_node, void *data,
        int (*compare) (void *, void *));

struct dl_node *insert_data_after(struct dl_list *list, struct dl_node *node,
        void *data);

struct dl_node *insert_data_before(struct dl_list *list, struct dl_node *node,
        void *data);

struct dl_node *insert_data_beginning(struct dl_list *list, void *data);

struct dl_node *insert_data_end(struct dl_list *list, void *data);

void remove_node(struct dl_list *list, struct dl_node *node);

#endif
