// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Create hashTable
node *hashtable[HASHTABLE_SIZE];

// word count
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    // Convert to lower case
    int word_len = strlen(word);
    char word_copy[word_len + 1];

    // Make all letters lower
    for (int w = 0; w < word_len; w++) {
        word_copy[w] = tolower(word[w]);
    }

    // Add \0
    word_copy[word_len] = '\0';

    // Get word hash
    int hash = hash_function(word_copy);

    node *cursor = hashtable[hash];

    // If node doesn't exist, return false
    if (cursor == NULL) {
        return false;
    }

    while(cursor != NULL) {
        // If the word matches
        if (strcmp(cursor->word,word_copy) == 0) {
            return true;
        }

        // Reference next item in the linked list
        else
        {
            cursor = cursor->next;
        }
    }

    // word cannot be found
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open input file
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        printf("Could not open dictionary");
        return false;
    }

    // Max line length + 1
    char word[LENGTH + 1];


    // Clean up the memory
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // Run through the list
    while( fscanf(dict,"%s", word) != EOF ) {

        // Create node
        node *new_node = malloc(sizeof(node));

        // Check node has been created
        if(new_node == NULL) {

            unload();
            return false;
        }

        // Place values in new_node
        new_node->next = NULL;
        strcpy(new_node->word, word);

        word_count++;


        // Hash the word
        int hash = hash_function(new_node->word);
        node *head = hashtable[hash];

        // If this is the first time we've accessed this array location
        if(head == NULL) {
            hashtable[hash] = new_node;
        }
        else
        // Point next to the exisiting initial node location
        // Point hashtable to the new node location
        {
            new_node->next = hashtable[hash];
            hashtable[hash] = new_node;
        }
    }

    // Close the file
    fclose(dict);

    return true;
}

// https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
unsigned int hash_function(const char *word) {

    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++) {
        hash = (hash << 2) ^ word[i];
    }

    return hash % HASHTABLE_SIZE;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Clean up the memory
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hashtable[i];

        while(cursor != NULL) {

            node *temp = cursor;

            cursor = cursor->next;

            free(temp);

        }
    }


    return true;
}
