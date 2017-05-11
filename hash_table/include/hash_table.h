#ifndef __HASHTABLE__
#define __HASHTABLE__

#include "list.h"

struct Hash_table {
    int table_size;
    struct Node **lists;
};

/*
 * Preconditions: none
 * Postconidtions: an empty initialized hash table is created
 */
struct Hash_table *create_hash_table(int table_size);

/*
 * Preconditions: an initialized hash table
 * Postconidtions: the hash table is destroyed along with all references to data
 */
void destroy_hash_table(struct Hash_table *hash_table);

/*
 * Preconditions: an initialized hash table exists
 * Postconidtions: the size of the hash table has increased by one, the key and
 * data are stored with a reference leading from key to data
 */
void insert_data(struct Hash_table *hash_table, char *key, void *data);

/*
 * Preconditions: the key/data pair is stored in the hash table
 * Postconidtions: he key/data pair is no longer in the hash table. The length
 * of the hash table has decreased by one.
 */
void remove_data(struct Hash_table *hash_table, char *key,
    int (*compare) (void *, void *));

/*
 * Preconditions: the key/data pair is in the hash table
 * Postconidtions: the data is returned. The hash table is unchanged.
 */
void *lookup_data(struct Hash_table *hash_table, char *key,
    int (*compare) (void *, void *));

/*
 * Preconditions: a key/data pair exists for the given key
 * Postconidtions: the new data is associated with the given key
 */
void update_data(struct Hash_table *hash_table, char *key, void *new_data,
    int (*compare) (void *, void *));

/*
 * Preconditions: none
 * Postconidtions: a hash data will be generated
 */
unsigned int hash(char *key, int table_size);

#endif
