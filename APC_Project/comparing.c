#include "ll.h"

// Function to compare two linked lists representing numbers
int compare_data(Dlist *head1, Dlist *head2) {
    int count1 = 0, count2 = 0;
    Dlist *ptr1 = head1;
    Dlist *ptr2 = head2;

    // Count the number of digits in the first number
    while (ptr1 != NULL) {
        count1++;
        ptr1 = ptr1->next;
    }

    // Count the number of digits in the second number
    while (ptr2 != NULL) {
        count2++;
        ptr2 = ptr2->next;
    }

    // If the first number has more digits, it is larger
    if (count1 > count2) {
        return 1;
    }

    // If the second number has more digits, it is larger
    if (count1 < count2) {
        return 0;
    }

    // If both numbers have the same number of digits, compare digit by digit
    if (count1 == count2) {
        ptr1 = head1;
        ptr2 = head2;
        while (ptr1 != NULL) {
            // If a digit in the first number is smaller, the second is larger
            if (ptr1->data < ptr2->data) {
                return 0;
            }
            // If a digit in the first number is larger, the first is larger
            if (ptr1->data > ptr2->data) {
                return 1;
            }
            // Move to the next digit in both numbers
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        // If all digits are equal, the numbers are equal
        return 2;
    }
}
