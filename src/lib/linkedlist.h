#ifndef linked_list
#define linked_list 1
#include <stdlib.h>
#include <stdio.h>

#define DATA_SIZE 8

struct Node {
	char data;
	struct Node * next;
};

typedef struct LinkedList {
	int id;
	struct Node * head;
	int size;
} LinkedList;

struct Node * init_node(char data);

int getSize (LinkedList * list);

int insertNode (LinkedList * list, struct Node * node);

int insertNodeAt (LinkedList * list, struct Node * node, int pos);

struct Node * getNode (LinkedList * list, int pos);

int removeNode (LinkedList * list, struct Node * node);

int removeNodeBy (LinkedList * list, char data);

int removeNodeAt (LinkedList * list, int pos);

int removeLast (LinkedList * list);

int removeHead (LinkedList * list);

void printList (LinkedList * list);

int listIsEmpty(LinkedList * list);
#endif
