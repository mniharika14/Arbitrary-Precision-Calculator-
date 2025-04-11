#include "ll.h"

int insert_last(Dlist **head, Dlist **tail, int data)
{
	//Allocate memory for a node
	Dlist *new = malloc(sizeof(Dlist));

	if(new == NULL){
		return FAILURE;
	}

	new->data = data; //Assign data to the node
	new->prev = new->next = NULL; //Initialize previous and next pointers to NULL
	//If the list is empty, set head and tail to the new node
	if(*head == NULL){
		*head = *tail = new;
		return SUCCESS;
	}

	//Add the new node to the end of the list
	(*tail)->next = new; //Link current tail's next to new node
	new->prev = *tail; //Set the new node's prev pointer to the current tail
	*tail = new; //Update the tail to the new node
	return SUCCESS;
}
