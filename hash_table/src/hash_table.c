#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "list.h"

struct Hash_table *create_hash_table(int table_size)
{
    struct Hash_table *hash_table;
    int i;

    hash_table = malloc(sizeof *hash_table);
    if (hash_table == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    hash_table->table_size = table_size;
    hash_table->lists = calloc(hash_table->table_size, sizeof(struct Node));

    for (i = 0; i < hash_table->table_size; i++) {
        hash_table->lists[i] = create_list();
    }

    return hash_table;
}


void destroy_hash_table(struct Hash_table *hash_table)
{
    int i;

    for (i = 0; i < hash_table->table_size; i++) {
        destroy_list(hash_table->lists[i]);
    }
    free(hash_table->lists);
    free(hash_table); 

    return;
}


void insert_data(struct Hash_table *hash_table, char *key, void *data)
{
    int hash_val;

    hash_val = hash(key, hash_table->table_size);
    add_front(hash_table->lists[hash_val], data);

    return;
}


void remove_data(struct Hash_table *hash_table, char *key,
    int (*compare) (void *, void *))
{
    int hash_val;
    struct Node *node;

    hash_val = hash(key, hash_table->table_size);

    node = delete_data(hash_table->lists[hash_val], key, compare);
    free(node);

    return;
}


void *lookup_data(struct Hash_table *hash_table, char *key,
    int (*compare) (void *, void *))
{
    int hash_val;

    hash_val = hash(key, hash_table->table_size);

    return find_data(hash_table->lists[hash_val], key, compare);
}


void update_data(struct Hash_table *hash_table, char *key, void *new_data,
    int (*compare) (void *, void *))
{
    struct Node *node;

    node = lookup_data(hash_table, key, compare);
    node->data = new_data;

    return;
}


unsigned int hash(char *key, int table_size)
{
    unsigned int hash_val;

    hash_val = 0;
    while (*key != '\0') {
        hash_val += *key++;
    }

    return hash_val % table_size;
}

