#include "ll.h"

/*
 * Function: addition
 * ------------------
 * This function adds two large numbers represented as doubly linked lists.
 *
 * Parameters:
 *   head1, tail1: Pointers to the head and tail of the first number list.
 *   head2, tail2: Pointers to the head and tail of the second number list.
 *   result_head, result_tail: Pointers to the head and tail of the result list.
 */
void addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail)
{
    int carry = 0, result, num1 = 0, num2 = 0;
    Dlist *ptr1 = tail1, *ptr2 = tail2;

    *result_head = NULL;  // Initialize the result list head to NULL
    *result_tail = NULL;  // Initialize the result list tail to NULL

    // Traverse both lists from the least significant digit to the most significant digit
    while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
        // If the first list is exhausted, set num1 to 0; otherwise, get the current digit
        if (ptr1 == NULL) {
            num1 = 0;
        } else {
            num1 = ptr1->data;
            ptr1 = ptr1->prev;  // Move to the previous node
        }

        // If the second list is exhausted, set num2 to 0; otherwise, get the current digit
        if (ptr2 == NULL) {
            num2 = 0;
        } else {
            num2 = ptr2->data;
            ptr2 = ptr2->prev;  // Move to the previous node
        }

        // Calculate the sum of the current digits and the carry
        result = num1 + num2 + carry;

        // Update the carry for the next iteration
        carry = result / 10;

        // Extract the last digit of the result
        result = result % 10;

        // Insert the digit at the beginning of the result list
        insert_first(result_head, result_tail, result);
    }
}
