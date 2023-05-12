#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 10000

typedef struct HashTableItem {
    char *key;
    char *value;
    struct HashTableItem *next;
} HashTableItem;

typedef struct HashTable {
    HashTableItem **items;
} HashTable;

HashTable *createHashTable (void)
{
    // allocate table
    HashTable *hashtable = malloc(sizeof(HashTable));

    // allocate table items
    hashtable->items = malloc(sizeof(HashTableItem*) * TABLE_SIZE);

    // set each to null (needed for proper operation)
    int i = 0;
    for (; i < TABLE_SIZE; ++i)
    {
        hashtable->items[i] = NULL;
    }  
    return hashtable;
}

HashTableItem *hashtablePair (const char *key, const char *value)
{
    // allocate the entry
    HashTableItem *item = malloc(sizeof(HashTableItem));

    item->key = malloc(strlen(key) + 1);

    item->value = malloc(strlen(value) + 1);

    // copy the key and value in place
    strcpy(item->key, key);
    strcpy(item->value, value);

    // next starts out null but may be set later on
    item->next = NULL;

    return item;
}

/*
Hash function
generate a hash value that can be used to index or store the given key in a hash table or an array-based data structure.
*/
unsigned int hash (const char *key)
{
    unsigned long int value = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (unsigned int i = 0; i < key_len; ++i)
    {
        value = value * 37 + key[i];

    }

    // make sure value is 0 <= value < TABLE_SIZE

    value = value % TABLE_SIZE;

    return value;
}

void hashtableSet (HashTable *hashtable, const char *key, const char *value)
{
    unsigned int slot = hash(key);

    // look up an item set
    HashTableItem *entry = hashtable->items[slot];

    // no item means slot empty, insert immediately
    if (entry == NULL)
    {
        hashtable->items[slot] = hashtablePair(key, value);
        return;
    }

    HashTableItem *prev;

    // walk through each item in the slot, maintaining a pointer to the last item
    // reached or a matching key is found
    while (entry != NULL)
    {
        // check key
        if (strcmp(entry->key, key) == 0)
        {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new item to the end
    prev->next = hashtablePair(key, value);
}

char *hashtableGet (HashTable *hashtable, const char *key)
{
    unsigned int slot = hash(key);

    // look up an item set
    HashTableItem *entry = hashtable->items[slot];

    // no item means slot empty, return immediately
    if (entry == NULL)
    {
        return NULL;
    }

    // walk through each item in the slot, maintaining a pointer to the last item
    // reached aor a matching key is found
    while (entry != NULL)
    {
        // check key
        if (strcmp(entry->key, key) == 0)
        {
            // match found, return value
            return entry->value;
        }

        entry = entry->next;
    }

    // end of chain reached without a match, return null
    return NULL;
}

// leap through all items in the hash table
void hashtableDump (HashTable *hashtable) {
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        HashTableItem *entry = hashtable->items[i];

        if (entry == NULL)
        {
            continue;
        }

        printf("slot[%4d]: ", i);

        for (;;)
        {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main ()
{
    HashTable *ht = createHashTable();

    hashtableSet(ht, "name", "John Smith");
    hashtableSet(ht, "age", "27");
    hashtableSet(ht, "dob", "01/01/1990");

    hashtableDump(ht);
    return 0;
}