#include "ll.h"

void multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail, int sign)
{
    int num1, num2, carry = 0, mul, count = 0;
    Dlist *ptr1 = tail1;            // Pointer to traverse the first number from the least significant digit (tail1)
    Dlist *ptr2 = tail2;            // Pointer to traverse the second number from the least significant digit (tail2)
    Dlist *result1_head = NULL, *result1_tail = NULL;  // Temporary list to store intermediate results
    Dlist *result3_head = NULL, *result3_tail = NULL;  // Temporary list for storing final result after addition

    // Outer loop to traverse the first number (head1) from the least significant digit
    while(ptr1 != NULL){
        num1 = ptr1->data;         // Get the current digit of the first number
        ptr2 = tail2;              // Reset pointer for the second number to the least significant digit
        result1_head = NULL;       // Reset the temporary result list for each digit multiplication
        result1_tail = NULL;
        carry = 0;                 // Reset carry value for each multiplication cycle

        // Inner loop to traverse the second number (head2) from the least significant digit
        while(ptr2 != NULL){
            num2 = ptr2->data;     // Get the current digit of the second number
            mul = (num1 * num2) + carry;   // Multiply the digits and add carry from the previous multiplication
            carry = mul / 10;               // Calculate new carry
            mul = mul % 10;                // Get the remainder after division (digit to be stored in the result list)
            insert_first(&result1_head, &result1_tail, mul);  // Insert the current digit at the front of the result list
            ptr2 = ptr2->prev;            // Move to the next digit of the second number
        }

        // If there is any carry left after multiplying the digits, insert it into the result list
        if(carry != 0){
            insert_first(&result1_head, &result1_tail, carry);
        }

        // Add zeroes (as place value shifts) at the end of the result list for each cycle
        for(int i = 0; i < count; i++){
            insert_last(&result1_head, &result1_tail, 0);   // Insert 0's at the end of the result
        }
        
        // After calculating multiplication for the current digit of the first number,
        // add the intermediate result (result1_head) to the overall result (result_head)
        if(count > 0){
            addition(result1_head, result1_tail, *result_head, *result_tail, &result3_head, &result3_tail);   // Add intermediate result to the overall result
            free(*result_head);    // Free the old result list to avoid memory leak
            *result_head = result3_head;  // Update the result list with the new sum
            *result_tail = result3_tail;
            result3_head = NULL;   // Reset the temporary result list
            result3_tail = NULL;
        } else {
            *result_head = result1_head;  // If it's the first multiplication, initialize the result list
            *result_tail = result1_tail;
        }

        // Reset temporary result list for the next cycle
        result1_head = NULL;
        result1_tail = NULL;
        count++;     // Increment the count for shifting the place value in the next cycle
        ptr1 = ptr1->prev;  // Move to the next digit of the first number
    }

    // Remove leading zeros from the final result
    while((*result_head)->data < 1)
        (*result_head) = (*result_head)->next;

    // If the sign flag is set, negate the final result
    if(sign)
        (*result_head)->data = -((*result_head)->data);
}
