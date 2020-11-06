/* Implements a dictionary's functionality */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

#include "bool.h"

/* Dictionary word count */
unsigned int word_count = 0;

/* Represents a node in a hash table */
typedef struct node {
    char word[LENGTH + 1];
    struct node *next;
}
node;

/* Number of buckets in hash table assuming usage of default dictionary */
#define N 190788

/* Hash table */
node *table[N];

/* Returns true if word is in dictionary else false */
int check(const char *word) {
    unsigned int key;
    node *traverse_cursor;

    /* Hashing word input to determine which linked list to access */
    key = hash(word);

    /* Assigning traversing pointer to point at same node as head of list */
    traverse_cursor = table[key];

    while (traverse_cursor != NULL) {
        if (strcasecmp(word, traverse_cursor->word) == 0) {
            return TRUE;
        }
        traverse_cursor = traverse_cursor->next;
    }
    return FALSE;
}

/* Hashes word to a number */
unsigned int hash(const char *word) {
    unsigned long hash = 5381;
    int c;

    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % N;
}

/* Loads dictionary into memory, returning true if successful else false */
int load(const char *dictionary) {
    unsigned int key;
    char buffer[LENGTH + 1];

    /* Declaring dictionary_input */
    FILE *dictionary_input;

    /* Attempting to open dictionary */
    dictionary_input = fopen(dictionary, "r");

    /* Exiting program upon unsuccessful retrieval */
    if (dictionary_input == NULL) {
        return FALSE;
    }

    /* Scanning words into hashtable */
    while (fscanf(dictionary_input, "%s", buffer) == 1) {
        /* Allocating memory to store node */
        node *new_node = malloc(sizeof(node));

        /* Exiting program upon unsuccessful retrieval */
        if (new_node == NULL) {
            return FALSE;
        }

        /* Copying word from buffer into node */
        strcpy(new_node->word, buffer);

        /* Hashing word */
        key = hash(new_node->word);

        /* Adding new node to beginning of linked list */
        new_node->next = table[key];
        table[key] = new_node;

        /* Incrementing dictionary word count */
        word_count++;
    }

    /* Closing dictionary */
    fclose(dictionary_input);

    /* Exiting program upon successful retrieval */
    return TRUE;
}

/* Returns number of words in dictionary if loaded else 0 if not yet loaded */
unsigned int size(void) {
    return word_count;
}

/* Unloads dictionary from memory, returning true if successful else false */
void unload(void) {
    int i;

    for (i = 0; i < N; i++) {
        node *lead_cursor = table[i];
        node *trail_cursor = lead_cursor;

        while (lead_cursor != NULL) {
            lead_cursor = lead_cursor->next;
            free(trail_cursor);
            trail_cursor = lead_cursor;
        }
    }
}
