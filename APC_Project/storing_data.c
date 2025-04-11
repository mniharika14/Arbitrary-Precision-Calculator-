#include "ll.h"

// Function to store a string of digits as a doubly linked list
int store_data(char str[], Dlist **head, Dlist **tail) {
    int i = 0;

    // Loop through each character in the string until the null terminator
    while (str[i] != '\0') {
        // Convert the character digit to an integer (ASCII to integer)
        int data = str[i] - 48;

        // Insert the integer into the linked list
        insert_last(head, tail, data);

        // Move to the next character in the string
        i++;
    }

    // Return success code
    return SUCCESS;
}
