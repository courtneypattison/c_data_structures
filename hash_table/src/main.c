#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "phone_dir.h"
#include "list.h"

#define TABLE_SIZE 3
#define MAX_PHONE_RECORD 4

void print_test(int boolean);

struct Phone_record *init_phone_record(struct Phone_record *phone_record);

int main(void)
{
    struct Hash_table *hash_table = create_hash_table(TABLE_SIZE);
    struct Phone_record *phone_record;
    struct Node *node = malloc(sizeof *node);;
    int i;
    unsigned int hash_val;

    
    printf("\nHash Table Testing\n"
             "==================\n");

    printf("\ncreate_hash_table()\n"
             "-----------------\n");
    print_test(TABLE_SIZE == hash_table->table_size);
    printf("hash_table->table_size\texpected: %d, actual: %d\n", TABLE_SIZE,
        hash_table->table_size);

    phone_record = calloc(MAX_PHONE_RECORD, sizeof *phone_record);
    if (phone_record == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    init_phone_record(phone_record);

    for (i = 0; i < hash_table->table_size; i++) {
        insert_data(hash_table, phone_record[i].phone_number, &phone_record[i]);
    }

    printf("\ninsert_data()\n"
             "-------------\n");
    print_test(
        strcmp((*(struct Phone_record*)hash_table->lists[2]->next->data).phone_number,
        phone_record[1].phone_number) == 0);
    printf("hash_table->lists[2]->next->data->key\texpected: %s,%s,%s ",
        phone_record[1].last_name, phone_record[1].first_name,
        phone_record[1].phone_number);
    printf("actual: ");
    print_phone_record(hash_table->lists[2]->next->data);

    printf("\nPrinted Hash Table\n"
             "------------------\n");
    for (i = 0; i < hash_table->table_size; i++) {
        print_list(hash_table->lists[i], print_phone_record);
    }

    printf("\nlookup_data()\n"
             "-------------\n");
    node = lookup_data(hash_table, "3", compare_phone_record_key);
    print_test(
        strcmp((*(struct Phone_record*)hash_table->lists[0]->next->data).phone_number,
        phone_record[2].phone_number) == 0);
    printf("lookup_data(hash_table, \"3\", compare_phone_record_key)\texpected: %s,%s,%s ",
        phone_record[2].last_name, phone_record[2].first_name,
        phone_record[2].phone_number);
    printf("actual: ");
    print_phone_record(node->data);

    printf("\nupdate_data()\n"
             "-------------\n");
    update_data(hash_table, "2", &phone_record[3], compare_phone_record_key);
    node = lookup_data(hash_table, "2", compare_phone_record_key);
    print_test(
        strcmp((*(struct Phone_record*)hash_table->lists[2]->next->data).phone_number,
        phone_record[3].phone_number) == 0);
    printf("update_data(hash_table, \"2\", &phone_record[3], compare_phone_record_key)"
           "\texpected: %s,%s,%s ",
        phone_record[3].last_name, phone_record[3].first_name,
        phone_record[3].phone_number);
    printf("actual: ");
    print_phone_record(node->data);

    printf("\nremove_data()\n"
             "-------------\n");
    remove_data(hash_table, "2", compare_phone_record_key);

    printf("remove_data(hash_table, \"2\", compare_phone_record_key\t expected: "
           "a hash table without Changed,Name,2\n");
    printf("\nPrinted Hash Table\n"
             "------------------\n");
    for (i = 0; i < hash_table->table_size; i++) {
        print_list(hash_table->lists[i], print_phone_record);
    }


    printf("\nhash()\n"
             "------\n");
    for (i = 0; i < hash_table->table_size; i++) {
        hash_val = hash(phone_record[i].phone_number, hash_table->table_size);
        print_test(hash_val == phone_record[i].phone_number[0] % hash_table->table_size);
        printf("hash(phone_record[%d].phone_number, hash_table->table_size)\t"
            "expected: %d actual: %d\n",
            i, phone_record[i].phone_number[0] % hash_table->table_size, hash_val);
    }

    printf("\ndestroy_hash_table()\n"
             "------------------\n");
    free(phone_record);
    destroy_hash_table(hash_table);

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


struct Phone_record *init_phone_record(struct Phone_record *phone_record)
{
    strcpy(phone_record[0].last_name, "Pattison");
    strcpy(phone_record[0].first_name, "Courtney");
    strcpy(phone_record[0].phone_number, "0");

    strcpy(phone_record[1].last_name, "Coolbeans");
    strcpy(phone_record[1].first_name, "Raj");
    strcpy(phone_record[1].phone_number, "2");

    strcpy(phone_record[2].last_name, "Pancake");
    strcpy(phone_record[2].first_name, "Lua");
    strcpy(phone_record[2].phone_number, "3");

    strcpy(phone_record[3].last_name, "Changed");
    strcpy(phone_record[3].first_name, "Name");
    strcpy(phone_record[3].phone_number, "2");

    return phone_record;
}
