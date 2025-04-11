#include "ll.h"

/*
 * Function: division
 * ------------------
 * This function divides two large numbers represented as doubly linked lists.
 * It performs long division, handling the quotient and remainder, and stores the result in a linked list.
 *
 * Parameters:
 *   head1, tail1: Pointers to the head and tail of the dividend list (first number).
 *   head2, tail2: Pointers to the head and tail of the divisor list (second number).
 *   result_head, result_tail: Pointers to the head and tail of the result list (quotient).
 *   sign: Integer representing the sign of the result (1 for negative, 0 for positive).
 */
void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign) {
    int ret_value, count = 0;
    Dlist *result1_head = NULL, *result1_tail = NULL;
    Dlist *temp_head = NULL, *temp_tail = NULL;

    // Iterate through each digit of the dividend
    while (head1 != NULL) {
        // Add the next digit of the dividend to temp_head
        insert_last(&temp_head, &temp_tail, head1->data);

        // Compare temp_head (current dividend part) with head2 (divisor)
        ret_value = compare_data(temp_head, head2);

        // If temp_head is smaller than head2, append 0 to the result and move to the next digit of dividend
        if (ret_value == 2) {
            insert_last(result_head, result_tail, 0);  // Append 0 to the result
            head1 = head1->next;  // Move to the next digit in the dividend
            continue;  // Skip the subtraction step
        }

        count = 0;  // Initialize count to hold the quotient digit

        // Perform repeated subtraction while temp_head is greater than or equal to head2
        while (compare_data(temp_head, head2) != 2) {
            // Subtract head2 from temp_head and update temp_head
            subtraction(temp_head, temp_tail, head2, tail2, &result1_head, &result1_tail, 0);
            temp_head = result1_head;  // Update temp_head after subtraction
            temp_tail = result1_tail;  // Update temp_tail after subtraction

            // Reset result1_head and result1_tail to NULL for the next iteration
            result1_head = NULL;
            result1_tail = NULL;
            count++;  // Increment the quotient count
        }

        // Append the quotient digit (count) to the result
        insert_last(result_head, result_tail, count);

        // Move to the next digit in the dividend
        head1 = head1->next;
    }

    // Remove any leading zeros in the result
    while (*result_head != NULL && (*result_head)->data == 0) {
        *result_head = (*result_head)->next;  // Skip the leading zeros
    }

    // Apply the sign to the first digit if the result is negative
    if (sign && *result_head != NULL) {
        (*result_head)->data = -((*result_head)->data);  // Make the first digit negative
    }

    // Print the final result (quotient)
    printf("Final result: ");
    Dlist *current = *result_head;
    while (current != NULL) {
        printf("%d", current->data);  // Print each digit of the quotient
        current = current->next;  // Move to the next digit
    }
    printf("\n");
}
