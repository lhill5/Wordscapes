
#ifndef LL_H
#define LL_H

struct node {
  char *word;
  struct node *next;
};

struct linkedList {
  int count;
  int min_length;
  struct node *head;
  struct node *tail;
};


#include "stdbool.h"
typedef struct node node;
typedef struct linkedList linkedList;

linkedList *linked_init();
void linked_push(linkedList *header, char *word);
void linked_pop(linkedList *header);
int linked_search(linkedList *header, char *search_word);
bool linked_inList(linkedList* header, char* word);
bool is_empty(linkedList *header);
void linked_print(linkedList *header);


#endif
