#include "../lib/linkedlist.h"

extern int debug;

struct Node * initNode(char data) {
	printf("[\e[93mlink\e[0m] Init note -> data: %c\n", data);
	struct Node * node = malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int getSize (LinkedList * list) {
	printf("[\e[93mlink\e[0m] Get size -> list: %p\n", &list);
	return list->size;
}

int insertNode(LinkedList * list, struct Node * node) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	if (node == NULL) {
		printf("Error - node to be inserted is null.\n");
		return -1;
	}
	printf("[\e[93mlink\e[0m] Insert node -> list: %p\tdata: %c\n", &list, node->data);
	struct Node * aux = list->head;
	if (aux == NULL) {
		if (debug)
			printf("NO HEAD!\n");
		list->head = node;
	} else {
		while(aux->next != NULL) {
			if (debug)
				printf("SIGUIENTE!\n");
			aux = aux->next;
		}
		aux->next = node;
	}
	list->size++;
	return 0;
}

int insertNodeAt (LinkedList * list, struct Node * node, int pos) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	if (node == NULL) {
		printf("Error - node to be inserted is null.\n");
		return -1;
	}
	if (pos < 0) {
		printf("Error - invalid position to insert at(%d/%d).\n", pos, list->size);
		return -1;
	}
	printf("[\e[93mlink\e[0m] Insert node -> list: %p\tdata: %c\tpos: %d\n", &list, node->data, pos);
	struct Node *aux = list->head;
	if (aux == NULL) {
		if (debug)
			printf("NO HEAD!\n");
		list->head = node;
	} else {
		if (pos == 0) { /* Insert on head */
			node->next = aux;
			list->head = node;
			list->size++;
			return 1;
		}
		while(pos > 1 && aux->next != NULL) {
			if (debug)
				printf("SIGUIENTE!\n");
			aux = aux->next;
			pos--;
		}
		node->next = aux->next;		
		aux->next = node;
	}
	list->size++;
	return 0;
}

struct Node * getNode (LinkedList * list, int pos) {	
	if (list == NULL) {
		printf("Error - list is null.\n");
		return NULL;
	}
	if (pos < 0 || pos > list->size) {
		printf("Error - invalid position to look for (%d/%d).\n", pos, list->size);
		return NULL;
	}
	struct Node * aux = list->head;
	while (pos > 0 && aux->next != NULL) {
		aux = aux->next;
		pos--;
	}
	return aux;
}

int removeNode (LinkedList * list, struct Node * node) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	if (node == NULL) {
		printf("Error - node to be remove is null.\n");
		return -1;
	}
	printf("[\e[93mlink\e[0m] RemoveNode -> node: %p\tdata: %c\n", node, node->data);
	struct Node * aux = list->head;
	if (aux == node) {
		list->head =  aux->next;
		printf("[\e[93mlink\e[0m] RemoveNode: node removed.\n");
		list->size--;
		return 0;
	}
	while (aux->next != NULL) {
		if (debug)
			printf("[\e[93mlink\e[0m] RemoveNode -> aux.next: %p\tdata: %c\n", aux->next, aux->next->data);
		if (aux->next == node) {
			aux->next = aux->next->next;
			printf("[\e[93mlink\e[0m] RemoveNode: node removed.\n");
			list->size--;
			return 0;
		}
		if (debug)
			printf("SIGUIENTE!\n");
		aux = aux->next;
	}
	printf("[\e[93mlink\e[0m] RemoveNode: cannot find the node.\n"); 
	return 1;
}

int removeNodeBy(LinkedList * list, char data) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	printf("[\e[93mlink\e[0m] RemoveNodeBy -> data: %c\n", data);
	struct Node * aux = list->head;
	if (aux->data == data) {
		list->head = aux->next;
		printf("[\e[93mlink\e[0m] RemoveNodeBy: node removed.\n");
		list->size--;
		return 0;
	}
	while (aux->next != NULL) {	
		if (debug)
			printf("[\e[93mlink\e[0m] RemoveNodeBy -> aux.next: %p\tdata: %c\n", aux->next, aux->next->data);
		if (aux->next->data == data) {
			aux->next = aux->next->next;
			printf("[\e[93mlink\e[0m] RemoveNodeBy: node removed.\n");
			list->size--;
			return 0;
		}
		if (debug)
			printf("SIGUIENTE!\n");
		aux = aux->next;
	}
	printf("[\e[93mlink\e[0m] RemoveNodeBy: cannot find the node.\n"); 
	return 1;
}

int removeLast (LinkedList * list) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	struct Node * aux = list->head;
	while (aux->next->next != NULL) {
		aux = aux->next;
	}
	aux->next = NULL;
	list->size--;
	return 0;
}

int removeHead (LinkedList * list) {	
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}	
	printf("[\e[93mlink\e[0m] RemoveHead -> head:  %p\tnext: %p\n", &(list->head), &(list->head->next));	
	if (list->head == NULL) {
		printf("[\e[93mlink\e[0m] List is empty. No head to be removed.\n");
		return 2;
	} else {
		list->head = list->head->next;
		list->size--;
		return 0;
	}
}

void printList (LinkedList * list) {
	if (list == NULL) {
		printf("Error - list is null.\n");
		return;
	}
	printf("[\e[93mlink\e[0m] printList head: %p\t data: %c\n", list->head, list->head->data);
	struct Node *aux = list->head;
	while (aux != NULL) {
		printf("[\e[93mlink\e[0m] Node->data: %c\n", aux->data);
		aux = aux->next;
	}
}

int listIsEmpty(LinkedList * list) {	
	if (list == NULL) {
		printf("Error - list is null.\n");
		return -1;
	}
	struct Node *aux = list->head;
	if (aux == NULL || getSize(list) <= 0) {
		return 1;
	}
	return 0;
}
