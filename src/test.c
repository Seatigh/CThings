#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/linkedlist.h"
#include "../lib/stack.h"

int factorial (int n);
void printS(char * s);

int debug = 0;

int main (int argc, char ** args) {	
	char *debug_env_var = getenv("DEBUG");

	if (debug_env_var != NULL) {
		debug = 1;	
	}
	printf("[\e[92mmain\e[0m] DEBUG MODE: %s\n", debug ? "enabled" : "disabled");
	/*************
	 * FACTORIAL *
	 *************/
	/*printf("[\e[92mmain\e[0m] Factorial 4: %d\n", factorial(4));
	char text [20]  = {0};
	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0)
			text[i]  += 97;
		else if (i % 7 == 0)
			text[i]  += 100;
	}
	printS(text);*/
	
	/*********
	 * STACK *
	 *********/	
	stack s;
	s.pointer = 0;
	unsigned char c = 'a';
	top(&s);
	pop(&s);
	push(&s, c);
	//printf("[\e[92mmain\e[0m] Test stack!%c\n", s.stack[0] );
	top(&s);
	for (int i = 0; i < SIZE - 1; i++) {
		c++;
		push(&s, c);
		top(&s);
	}
	printf("[\e[92mmain\e[0m] Drop the bass!\n");
	while (!isEmpty(&s)) {
		printf("[\e[92mmain\e[0m] %d\n", (int) pop(&s));
	}
	/***************
	 * LINKED LIST *
	 ***************/
/*	printf("[\e[92mmain\e[0m] ___________TEST LINKED LIST___________\n\n");
	LinkedList list;
	list.head = NULL;
	list.size = 0;
	printf("[\e[92mmain\e[0m] Remove head(%d)\n", removeHead(&list));
	printf("[\e[92mmain\e[0m] IsEmpty(%d)\n", listIsEmpty(&list)); 
	//printList(&list);
	for (int i = 97; i < 107; i++) {
		struct Node* n = initNode((char) i);
		printf("[\e[92mmain\e[0m] Insert(%d)\n", insertNode(&list, n));
		printList(&list);
	}	//struct Node n = initNode(d, NULL);
	//struct Node n = initNode(d, NULL);
	//printf("[\e[92mmain\e[0m] Node:\n\tdata: %c\tnext: \n", head->data);
	//n.data++;
	//printf("[\e[92mmain\e[0m] Insert: %d\n", insertNode(&list, &n));
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), &list.head);	
	printf("[\e[92mmain\e[0m] Remove head(%d)\n", removeHead(&list));
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), &list.head);
	printf("[\e[92mmain\e[0m] InsertAt(%d)\n", insertNodeAt(&list, initNode('z'), 0));
	printList(&list);
	printf("[\e[92mmain\e[0m] InsertAt(%d)\n", insertNodeAt(&list, initNode('x'), 4));
	printList(&list);
	printf("[\e[92mmain\e[0m] InsertAt(%d)\n", insertNodeAt(&list, initNode('y'), 20));
	printList(&list);
	printf("[\e[92mmain\e[0m] RemoveLast(%d)\n", removeLast(&list));
	printList(&list);
	printf("[\e[92mmain\e[0m] RemoveLast(%d)\n", removeLast(&list));
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), &list.head);
	printf("[\e[92mmain\e[0m] InsertAt(%d)\n", insertNodeAt(&list, initNode('a'), 0));
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), list.head);
	struct Node * gNode = getNode(&list, 0);
	printf("[\e[92mmain\e[0m] Get node: %p\tdata: %c\tnext: %p\n", gNode, gNode->data, gNode->next);
	printf("[\e[92mmain\e[0m] RemoveNode(%d)\n", removeNode(&list, gNode));
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), list.head);
	struct Node * rNode = getNode(&list, 20);
//	printf("[\e[92mmain\e[0m] Get node: %p\tdata: %c\tnext: %p\n", rNode, rNode->data, rNode->next);
	rNode = getNode(&list, 5);
	printf("[\e[92mmain\e[0m] Get node: %p\tdata: %c\tnext: %p\n", rNode, rNode->data, rNode->next);
	printf("[\e[92mmain\e[0m] RemoveNode(%d)\n", removeNode(&list, rNode));
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), list.head);
	gNode = getNode(&list, 9);
	printf("[\e[92mmain\e[0m] Get node: %p\tdata: %c\tnext: %p\n", getNode, gNode->data, gNode->next);
	printf("[\e[92mmain\e[0m] RemoveNodeBy(%d)\n", removeNodeBy(&list, 'x')); 
	printList(&list);
	printf("[\e[92mmain\e[0m] List info:\n\tsize: %d\n\thead: %p\n", getSize(&list), list.head);
	printf("[\e[92mmain\e[0m] IsEmpty(%d)\n", listIsEmpty(&list));
*/
	return 0;
}

/** name: factorial
  * parameters: integer
  * return: integer
  */

int factorial (int n) {
	
	if (n < 0) {
		printf("[\e[92mmain\e[0m] Error: there's no exist factorial of negative number.\n");
		return -1;
	}
	if (n <= 1) {
		return 1;
	} else {
		return n*factorial(n - 1);
	}
}

/** name: printS
  * parameter: char pointer
  * return: void
  */

void printS(char * s) {
	char c = '0';
	for (int i = 0; i < 20; i++) {
		if (s[i]  == 'd') {
			c = s[i] ;
			printS("01234567890123456789");
		}
		printf("[\e[92mmain\e[0m] text[%d] : %c\tc: %c\n", i, s[i] , c);
	}
}
