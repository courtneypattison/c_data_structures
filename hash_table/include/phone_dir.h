#ifndef __PHONEDIR__
#define __PHONEDIR__

#include "hash_table.h"
#include "list.h"

/* maximums determined by canadapost.ca/cpo/mc/assets/pdf/business/import_en.pdf */
#define MAX_FNAME 30
#define MAX_LNAME 40
#define MAX_PHONE 10
#define MAX_ROW MAX_FNAME + 1 + MAX_LNAME + 1 + MAX_PHONE + 1

struct Phone_record {
    char first_name[MAX_FNAME + 1];
    char last_name[MAX_LNAME + 1];
    char phone_number[MAX_PHONE + 2];
};

/*
 * Preconditions: a formatted phone file
 * Postconditions: phone file is opened and closed
 */
void access_phone_file(const char *filename, struct Node *phone_list);

/*
 * Preconditions: two initialized phone records
 * Postconditions: return value determined by match between phone record keys
 */
int compare_phone_record_key(void *value1, void *value2);

/*
 * Preconditions: an initialized list of phone records
 * Postconditions: a hashtable with keys that reference phone records
 */
void hash_phone_dir(struct Node *phone_list, struct Hash_table *hash_table);

/*
 * Preconditions: an initialized phone record list and hash table
 * Postconditions:  a new node in the list and key/value pair in the hash table
 */
void add_phone_record(struct Node *phone_list, struct Hash_table *hash_table);

/*
 * Preconditions: an initialized phone list
 * Postconditions: an empty phone list
 */
void destroy_phone_record(struct Node *phone_list);

/*
 * Preconditions: an initialized and populated phone list and hash table
 * Postconditions: the phone record is printed to the screen
 */
void lookup_name(struct Hash_table *hash_table);

/*
 * Preconditions: none
 * Postconditions: the menu for the phone directory is printed to the screen
 */
void print_menu();

/*
 * Preconditions: an initialized phone record
 * Postconditions: the phone record is printed to the screen
 */
void print_phone_record(void *value);

/*
 * Preconditions: an initialized phone list
 * Postconditions: the phone list is printed to the screen
 */
void print_phone_dir(struct Node *phone_list);

#endif
