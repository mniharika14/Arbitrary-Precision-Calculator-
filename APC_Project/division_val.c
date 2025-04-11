#include "ll.h"

// Function to check if the linked list represents a non-zero number
int division_val(Dlist *head2) {
    int count1 = 0;

    // Traverse the linked list
    while (head2 != NULL) {
        // Add the data of the current node to count1
        count1 = count1 + head2->data;

        // Move to the next node
        head2 = head2->next;
    }

    // If count1 is non-zero, return 1 (indicating a non-zero number)
    if (count1)
        return 1;

    // Otherwise, return 0 (indicating a zero number)
    return 0;
}
