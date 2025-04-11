#include "ll.h"

// Function to check if the multiplication of two linked list numbers results in zero
int multiplication_val(Dlist *head1, Dlist *head2) {
    int num1 = 0, num2 = 0;

    // Calculate the sum of digits in the first linked list
    while (head1 != NULL) {
        num1 = num1 + head1->data; // Add the current node's data to num1
        head1 = head1->next;       // Move to the next node
    }

    // If the sum of the first list is zero, return 0 
    if (num1 == 0)
        return 0;

    // Calculate the sum of digits in the second linked list
    while (head2 != NULL) {
        num2 = num2 + head2->data; // Add the current node's data to num2
        head2 = head2->next;       // Move to the next node
    }

    // If the sum of the second list is zero, return 0
    if (num2 == 0)
        return 0;

    // If neither list has a sum of zero, return 1 
    return 1;
}
