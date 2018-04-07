// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASHTABLE_SIZE 65536 // largest unsigned int

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
unsigned int hash_function(const char *word);
bool unload(void);


// Structs
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


#endif // DICTIONARY_H
