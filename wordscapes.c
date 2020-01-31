/* DONE */

#define for_each_item(item, list) \
	for (node* item = list->head; item != NULL; item = item->next)

#include "linkedList.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node node;
typedef struct linkedList linkedList;


void push(char** string, char c);
void pop(char** string);
void letter_combination(linkedList* ws_words, char* letters, char* string);
// linkedList* linked_init();
// void linked_push(linkedList* ws_words, char* word);
// void linked_pop();
// void linked_print(linkedList* ws_words);
char* get_input();
int str_count(char* string, char letter);
void parse_dictionary(linkedList** hashTable);


int main(void) {
	char* string = malloc(10);
	linkedList* ws_words = linked_init();

	char* letters = get_input();
	letter_combination(ws_words, letters, string);

	linkedList** hashTable = hash_init();
	parse_dictionary(hashTable);

	for_each_item(item, ws_words) {
		char* word = item->word;
		int num_occurances = hash_search(hashTable, word);
		// if word was found in dictionary
		if (num_occurances > 0) {
			// for now print word, later add this to valid_words linkedList
			printf("%s\n", word);
		}
	}

	printf("\n");

  // char* string = "frankenstein";

	// linked_print(ws_words);
	return 0;
}


char* get_input() {
	char* input = malloc(100);
	printf("Enter wordscapes letters: ");
	fgets(input, 10, stdin);
	sscanf(input, "%s", input);
	printf("\n");
	return input;
}


void letter_combination(linkedList* ws_words, char* letters, char *string) {
	int length = strlen(letters);
	if (strlen(string) == strlen(letters)) {
		return;
	}
	for (int i = 0; i < length; i++) {
		// if letter not in string, what if string is aabc then aa would be valid
		// only skip if appending letter would exceed that letters count in original string
		// if string.count("a") + 1 > ws_words.count("a") then skip
		// string="a" -> 1, 1+1 = 2 > ws_words="abc".count("a") = 1, 2 > 1
		// if (strcmp(string, "aaa") != 0) {
		if ((str_count(string, letters[i]) + 1) <= str_count(letters, letters[i])) {
			push(&string, letters[i]);
			if (strlen(string) > ws_words->min_length) {
				if (!linked_inList(ws_words, string)) {
					char *temp = malloc(100);
					strcpy(temp, string);
					linked_push(ws_words, temp);
				}
			}
			// puts(string);
			letter_combination(ws_words, letters, string);
			pop(&string);
		}
	}
}


int str_count(char* string, char letter) {
	int count = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == letter) {
			count++;
		}
	}
	return count;
}


void push(char** string, char c) {
	int i = strlen(*string);
	*string = realloc(*string, strlen(*string) + 2);
	(*string)[i] = c;
		// (*string)[i+1] = '\0';
}

void pop(char** string) {
	int length = strlen(*string);
	(*string)[length-1] = '\0';
}

// linkedList* linked_init() {
// 	linkedList* header = (linkedList*)malloc(sizeof(linkedList));
// 	header->head = header->tail = NULL;
// 	header->count = 0;
// 	header->min_length = 2;
// 	return header;
// }
//
// void linked_push(linkedList* ws_words, char* word) {
// 	node* p = (node*)malloc(sizeof(node));
// 	p->word = word;
// 	p->next = NULL;
// 	if (ws_words->head == NULL) {
// 		ws_words->head = ws_words->tail = p;
// 	} else {
// 		ws_words->tail->next = p;
// 		ws_words->tail = p;
// 	}
// 	ws_words->count++;
// }
//
// void linked_pop() {
//
// }
//
// void linked_print(linkedList* ws_words) {
// 	node* p = ws_words->head;
// 	if (p == NULL) {
// 		printf("linked list is empty\n");
// 		return;
// 	}
//
// 	while (p != NULL) {
// 		printf("%s\n", p->word);
// 		p = p->next;
// 	}
// }

void parse_dictionary(linkedList** hashTable) {
  FILE *textFile = fopen("dictionary.txt", "r");
  if (textFile == NULL) {
    printf("Couldn't open text file\n");
    exit(-1);
  }

  char *string = malloc(100);
  while (fgets(string, 100, textFile)) {
    sscanf(string, "%s", string);
    string = realloc(string, strlen(string) + 1);
    hash_insert(hashTable, string);
    string = malloc(100);
  }
  free(string);
}
