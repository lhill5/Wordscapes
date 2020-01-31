#include "linkedList.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

linkedList** hash_init() {
  linkedList** hashTable = calloc(26, sizeof(linkedList *));
  int i;
  for (i = 0; i < 26; i++) {
    hashTable[i] = linked_init();
  }
  return hashTable;
}

int hash_key(char* word) {
  return (tolower(word[0]) - 'a');
}

void hash_insert(linkedList** hashTable, char* word) {
  int key = hash_key(word);
  // printf("key = %d\n", key);
  linked_push(hashTable[key], word);
}

int hash_search(linkedList** hashTable, char* search_word) {
  int key = hash_key(search_word);
  // printf("key = %d\n", key);
  return linked_search(hashTable[key], search_word);
}

void hash_print(linkedList** hashTable) {
  int i;
  for (i = 0; i < 26; i++) {
    printf("%c = ", i + 0x41);
    linked_print(hashTable[i]);
    printf("\n");
  }
}
