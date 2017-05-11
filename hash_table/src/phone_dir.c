#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "list.h"
#include "phone_dir.h"


static int compare_last_name(void *data1, void *data2)
{
    struct Phone_record *phone_record1, *phone_record2;
	int sort_data;
    phone_record1 = data1;
    phone_record2 = data2;

	sort_data = strcmp(phone_record1->last_name, phone_record2->last_name);
	if (sort_data <= 0) {
		return 0;
	} else {
		return 1;
	}
}


static void read_phone_file(FILE *phone_file, struct Node *phone_list)
{
    char row[MAX_ROW];
    while (fgets(row, MAX_ROW, phone_file) != NULL) {
        struct Phone_record *phone_record;
        const char delimeter[3] = ",\n";

        phone_record = malloc(sizeof *phone_record);
        if (phone_record == NULL) {
            fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }

        strcpy(phone_record->first_name, strtok(row, delimeter));
        strcpy(phone_record->last_name, strtok(NULL, delimeter));
        strcpy(phone_record->phone_number, strtok(NULL, delimeter));
        phone_record->phone_number[10] = '\0';

        add_sorted(phone_list, phone_record, compare_last_name);
    }

    return;
}


void access_phone_file(const char *filename, struct Node *phone_list)
{
    FILE *phone_file;

    phone_file = fopen(filename, "r");
    if (phone_file == NULL) {
        fprintf(stderr, "Sorry, %s cannot be accessed.\n", filename);
        fprintf(stderr, "%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    read_phone_file(phone_file, phone_list);

    fclose(phone_file);

    return;
}


int compare_phone_record_key(void *data1, void *data2)
{
    struct Phone_record *phone_record;
    char *key;
    key = data1;
    phone_record = data2;

	return strcmp(key, phone_record->phone_number);
}


void hash_phone_dir(struct Node *phone_list, struct Hash_table *hash_table)
{
    struct Node *current;
    struct Phone_record *phone_record;

    current = phone_list->next;
    while (current != NULL) {
        phone_record = current->data;
        insert_data(hash_table, phone_record->phone_number, current->data);
        current = current->next; 
    }
    return;
}


void add_phone_record(struct Node *phone_list, struct Hash_table *hash_table)
{
    struct Phone_record *phone_record;

    phone_record = malloc(sizeof *phone_record);
    if (phone_record == NULL) {
        fprintf(stderr, "%s:%d Null pointer", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
    printf("What is the phone number you would like to add?\n");
    scanf("%s", phone_record->phone_number);

    printf("What is the first name you would like to add?\n");
    scanf("%s", phone_record->first_name);

    printf("What is the last name you would like to add?\n");
    scanf("%s", phone_record->last_name);

    add_sorted(phone_list, phone_record, compare_last_name);
    insert_data(hash_table, phone_record->phone_number, phone_record);

    return;
}


void destroy_phone_record(struct Node *phone_list)
{
    struct Node *current;

    current = phone_list->next;
    while (current != NULL) {
        free(current->data);
        current = current->next;
    }

    return;
}


void lookup_name(struct Hash_table *hash_table)
{
    struct Node *node;
    char lookup_number[MAX_PHONE + 1];

    printf("What is the phone number you would like to look up?\n");
    scanf("%s", lookup_number);

    node = lookup_data(hash_table, lookup_number, compare_phone_record_key);
    printf("The record associated with this phone number is: ");
    print_phone_record(node->data);

    return;
}


void print_menu()
{
    printf("Choose from the following options, or press q to quit:\n"
           "1. Load new file\n"
           "2. Add phone number\n"
           "3. Print phone directory\n"
           "4. Lookup name\n");

    return;
}


void print_phone_record(void *data)
{
	struct Phone_record *phone_record = data;

	printf("%s,%s,%s\n", phone_record->last_name, phone_record->first_name,
		phone_record->phone_number);

	return;
}


void print_phone_dir(struct Node *phone_list)
{
	print_list(phone_list, print_phone_record);

	return;
}
