#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int insert_last(Dlist **head, Dlist **tail, int data);
int store_data(char str[], Dlist **head, Dlist **tail);
void addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail);
void print_list(Dlist *head);
int insert_first(Dlist **head, Dlist **tail, int result);
void subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign);
int compare_data(Dlist *head1, Dlist *head2);
void multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign);
int multiplication_val(Dlist *head1, Dlist *head2);
void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign);
int division_val(Dlist *head2);
void validation(char **str1, char **str2, char **str3, int *sign);
int validation_alpa(char *str, char *str1);
#endif
