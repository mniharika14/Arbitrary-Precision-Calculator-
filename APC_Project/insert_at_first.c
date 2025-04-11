#include "ll.h"

int insert_first(Dlist **head, Dlist **tail, int data){
	//Allocate memory for a new node
	Dlist *new = malloc(sizeof(Dlist));
	if(new == NULL){
		return FAILURE; //Return failure if memory allocation fails
	}

	new->data = data; //Assign data to the new node
	new->prev = new->next = NULL; //Initialize previous and next pointers to NULL

	//If the list is empty, set head and tail to the new node
	if(*head == NULL){
		*head = *tail = new;
		return SUCCESS;
	}

	//Add the new node at the beginning of the list
	new->next = *head; //Link the new node's next to the current head
	(*head)->prev = new; //Update the current head's previous to point to the new node
	*head = new; //Update the head to the new node
	return SUCCESS;
}
