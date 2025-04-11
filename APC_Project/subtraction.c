#include "ll.h"

void subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign) {
    int num1, num2, borrow = 0;

    Dlist *ptr1 = tail1;
    Dlist *ptr2 = tail2;
    int difference;

    while (ptr1 != NULL) {
        num1 = (ptr1->data) - borrow;
        ptr1 = ptr1->prev;
        borrow = 0;

        if (ptr2 != NULL) {
            num2 = ptr2->data;
            ptr2 = ptr2->prev;
        } else {
            num2 = 0;
        }

        if (num1 >= num2) {
            difference = num1 - num2;
        } else {
            num1 += 10;
            difference = num1 - num2;
            borrow = 1;
        }
        insert_first(result_head, result_tail, difference);
    }

    while((*result_head)->data < 1)
		*result_head = (*result_head)->next;
	if(sign == 0){
		(*result_head)->data = -((*result_head)->data);
	}
}
