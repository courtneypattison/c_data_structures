#ifndef __LIST__
#define __LIST__


struct Node {
	void *data;
	struct Node *next;
};

/*
 * Preconditions: none
 * Postconditions: a new list is created and is empty
 */
struct Node *create_list();

/*
 * Preconditions: none
 * Postconditions: a new node is created and populated with an integer
 */
struct Node *init_node(void *data);

/*
 * Preconditions: a list exists
 * Postconditions: the element is added to the front of the list and the length
 * of the list is increased by one
 */
struct Node *add_front(struct Node *head, void *data);

/*
 * Preconditions: a list exists
 * Postconditions: the element is added to the back of the list and the length
 * of the list is increased by one
 */
struct Node *add_back(struct Node *head, void *data);

/*
 * Preconditions: a list exists
 * Postconditions: the element is added the list sorted and the length
 * of the list is increased by one
 */
struct Node *add_sorted(struct Node *head, void *data,
    int (*compare) (void *, void *));

/*
 * Preconditions: a non-empty list is available
 * Postconditions: the first element in the list is returned
 */
struct Node *get_front(struct Node *head);

/*
 * Preconditions: a non-empty list is available
 * Postconditions: the last element in the list is returned
 */
struct Node *get_back(struct Node *head);

/*
 * Preconditions: a non-empty list is available
 * Postconditions: the first element of the list is removed, the length of the
 * list is decreased by one, and the removed element is returned
 */
struct Node *delete_front(struct Node *head);

/*
 * Preconditions: a non-empty list is available
 * Postconditions: an element of the list is removed based on the compare
 * function, the length of the list is decreased by one, and the removed
 * element is returned
 */
struct Node *delete_data(struct Node *head, void *data,
    int (*compare) (void *, void *));

/*
 * Preconditions: a list exists 
 * Postconditions: an element of the list that matches using the compare
 * function is returned
 */
struct Node *find_data(struct Node *head, void *data,
    int (*compare) (void *, void *));

/*
 * Preconditions: a list exists
 * Postconditions: the length of the list is returned
 */
int get_length(struct Node *head);

/*
 * Preconditions: a list exists
 * Postconditions: the list elements are printed separated by spaces
 */
void print_list(struct Node *head, void (*print) (void *));

/*
 * Preconditions: a list exists
 * Postconditions: the list is destroyed
 */
void destroy_list(struct Node *head);

#endif
