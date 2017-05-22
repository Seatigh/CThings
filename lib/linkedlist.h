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

struct LinkedList * initList (int id);/**/

struct Node * initNode (char data);/*x*/

int getSize (LinkedList * list);/*x*/

int insertNode (LinkedList * list, struct Node * node);/*x*/

int insertNodeAt (LinkedList * list, struct Node * node, int pos);/*x*/

struct Node * getNode (LinkedList * list, int pos);/*x*/

int removeNode (LinkedList * list, struct Node * node);/*x*/

int removeNodeBy (LinkedList * list, char data);/*x*/

int removeNodeAt (LinkedList * list, int pos);/**/

int removeLast (LinkedList * list);/*x*/

int removeHead (LinkedList * list);/*x*/

void printList (LinkedList * list);/*x*/

int listIsEmpty(LinkedList * list);/*x*/
#endif
