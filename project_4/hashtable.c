// HashTable Implementation Starter Code
// CMS 230, 2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hashtable struct definitions and function prototypes
#include "hashtable.h"


//*** Hash a string to an integer ***//
// Input
//    char *s: the string to hash
// Returns
//    The integer hash code
//
// Implements the basic hashing String hashing algorithm used by Java.
unsigned long int hash(char *s) {
    unsigned long int h = 0;

    int i;
    for (i = 0; i < strlen(s); i++) {
        h += h * 31 + (unsigned long int) s[i];
    }

    return h;
}


//*** Create a new hashtable_t ***//
// Input
//    tableSize: the number of buckets in the new table
// Returns
//    A pointer to the new table
HashTable * hashtableInit(int tableSize) {

    // Allocate memory for a new HashTable
    HashTable* ht = malloc(sizeof(HashTable));
    
    // check to make sure hashtable is created correctly
    if(!ht){
        return NULL;
    }
    
    // Allocate memory for an array of buckets and assign
    // them to the table's buckets field
    ht->buckets = (HashNode**)malloc(sizeof(HashNode*)*tableSize);
    for(int i = 0; i < tableSize; i++){
        ht->buckets[i] = NULL;
    }

    // Set the new HashTable's size field
    ht->size = tableSize;

    // Return the new HashTable
    return ht;
}

//*** Destroy (de-allocate a hashtable) ***//
// Input:
//     hashtable *ht: the hashtable to delete
// Returns:
//     Nothing
void hashTableDestroy(HashTable *ht) {

    // Free memory for array of buckets
    for(int i = 0; i < ht->size; i++){
        HashNode* bucket = ht->buckets[i];
        if(bucket != NULL){
            free(bucket->key);
            free(bucket->value);
            free(bucket);
        }
    }

    // Free memory for hashtable
    free(ht->buckets);
    free(ht);
}


//*** Insert a key-value pair into a table ***//
// Inputs
//    hashtable *h: the hashtable performing the insertion
//    char *key: the key string
//    char *value: the value string
// Returns
//    Nothing
void hashtableInsert(HashTable *h, char *key, char *value) {
    
    // allocate memory and store values in node
    HashNode* head = malloc(sizeof(HashNode));
    head->key = key;
    head->value = value;
    head->next = NULL;
    
    // use hash function to find index
    int index = hash(key) % h->size;
    
    // insert the key/value pair in front of list
    if(h->buckets[index] == NULL){
        h->buckets[index] = head;
    } else {
        HashNode* temp = h->buckets[index];
        h->buckets[index] = head;
        head->next = temp;
    }
}


//*** Lookup the value associated with a particular key ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find
// Returns
//    The char *value associated with the key or NULL if no match exists
char * hashtableLookup(HashTable *h, char *key) {
    int index = hash(key) % h->size;
    HashNode* node = h->buckets[index];
    
    while(node != NULL){
        if(!strcmp(node->key, key)){
            return node->value;
        }
        node = node->next;
    }
    
    return NULL;
}


//*** Remove a key-value pair from the table if it exists ***//
// Inputs
//    hashtable_t *h: the table
//    char *key: the key to find and remove
// Returns
//    The char *value associated with the key or NULL if no match exists
//    The pair is removed if it exists in the table
char * hashtableRemove(HashTable *h, char *key) {
    int index = hash(key) % h->size;
    HashNode* curr = h->buckets[index];
    HashNode* prev = NULL;
    char* value = NULL;
    
    while(curr != NULL){
        if(!strcmp(curr->key, key)){
            if(prev != NULL){
                HashNode* temp = curr;
                value = curr->value;
                prev->next = temp->next;
                curr->key = NULL;
                curr->value = NULL;
                free(curr);
                return value;
            } else {
                HashNode* temp = curr;
                value = temp->value;
                h->buckets[index] = temp->next;
                curr->key = NULL;
                curr->value = NULL;
                free(curr);
                return value;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    return NULL;
}


//*** Print a hashtable ***//
// Input
//    hashtable_t *h: the table
// Output
//    the hashtable, printed by buckets
void hashtablePrint(HashTable *h) {
    int i;
    for (i = 0; i < h->size; i++) {
        HashNode *node = h->buckets[i];
        printf("Contents of bucket %d:\n", i);

        while (node != NULL) {
            printf("    <%s, %s>\n", node->key, node->value);
            node = node->next;
        }
    }
}

//*** There is no main function --- use main.c *** //
