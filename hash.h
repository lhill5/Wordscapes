#ifndef HASH_H
#define HASH_H

linkedList** hash_init();
int hash_key(char *word);
void hash_insert(linkedList** hashTable, char* word);
int hash_search(linkedList** hashTable, char* search_word);
void hash_print(linkedList** hashTable);

#endif
