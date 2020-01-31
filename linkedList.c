// lined list functions
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

linkedList* linked_init() {
  linkedList* header = malloc(sizeof(struct linkedList));
  if (header == NULL) exit(-1);
  header->count = 0;
  header->head = NULL;
  header->tail = NULL;
  header->min_length = 2;
  return header;
}

void linked_push(linkedList* header, char* word) {
  if (header == NULL) {
    return;
  }
  node* temp = malloc(sizeof(struct node));
  temp->word = word;
  temp->next = NULL;
  if (header->head == NULL) {
    header->head = header->tail = temp;
  } else {
    header->tail->next = temp;
    header->tail = temp;
  }
  (header->count)++;
}

void linked_pop(linkedList* header) {
  if (header == NULL || header->count == 0) {
    return;
  }
  node* temp = header->head;
  header->head = header->head->next;
  if (header->head == NULL) {
    header->tail = NULL;
  }
  (header->count)--;
  free(temp);
}

int linked_search(linkedList* header, char* search_word) {
  node* p = header->head;
  int count = 0;
  while (p) {
    if (strcmp(p->word, search_word) == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

bool linked_inList(linkedList* header, char* word) {
  if (header == NULL) return false;

  for (node* p = header->head; p != NULL; p = p->next) {
    if (strcmp(p->word, word) == 0) {
      return true;
    }
  }
  return false;
}

bool is_empty(linkedList* header) {
  if (header == NULL || header->count == 0) {
    return 1;
  } else {
    return 0;
  }
}

void linked_print(linkedList* header) {
  if (header == NULL) return;

  int count = 0;
  node* p = header->head;

  while (p) {
    printf("%s ", p->word);
    p = p->next;
    count++;
    if (count % 10 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}
