/*
Project: Arbitrary Precision Calculator
A simple arbitrary precision calculator which can perform addition, subtraction, division, and multiplication.
Name: Niharika
Date: 31-12-2024
*/

#include "ll.h"

int main(int argc, char *argv[])
{
    int ret_value, zero;
    
    // Validate the input arguments
    ret_value = validation_alpa(argv[1], argv[3]);
    
    // If validation passes
    if (ret_value) {
        int sign = 0;
        
        // Check if the sign argument is present (if there are more than 4 arguments)
        if (argc >= 5)
            argv[2][0] = 4;  // Arbitrary assignment based on the input

        // Validate the input numbers and operator
        validation(&argv[1], &argv[2], &argv[3], &sign);

        // Initialize pointers for linked list representations of numbers
        Dlist *head1 = NULL;             // Initialize head1 to NULL (first number)
        Dlist *tail1 = NULL;             // Initialize tail1 to NULL
        Dlist *head2 = NULL;             // Initialize head2 to NULL (second number)
        Dlist *tail2 = NULL;             // Initialize tail2 to NULL
        Dlist *result_head = NULL;       // Initialize result_head to NULL (for storing result)
        Dlist *result_tail = NULL;       // Initialize result_tail to NULL

        // Switch case to perform operations based on the operator in argv[2][0]
        switch (argv[2][0]) {
            case '+':  // Addition case
                store_data(argv[1], &head1, &tail1);  // Store first number (argv[1]) in linked list
                store_data(argv[3], &head2, &tail2);  // Store second number (argv[3]) in linked list
                addition(head1, tail1, head2, tail2, &result_head, &result_tail);  // Perform addition
                while (result_head && result_head->data < 1)  // Skip leading zeros in result
                    result_head = result_head->next;
                if (sign && result_head)  // Apply sign to the result if negative
                    result_head->data = -(result_head->data);

                // Print the result
                Dlist *temp = result_head;
                while (temp != NULL) {
                    printf("%d", temp->data);  // Print each digit of the result
                    temp = temp->next;
                }
                printf("\n");
                break;
            
            case '-':  // Subtraction case
                store_data(argv[1], &head1, &tail1);  // Store first number (argv[1]) in linked list
                while (head1->data < 1)  // Skip leading zeros in first number
                    head1 = head1->next;
                store_data(argv[3], &head2, &tail2);  // Store second number (argv[3]) in linked list
                while (head2->data < 1)  // Skip leading zeros in second number
                    head2 = head2->next;

                ret_value = compare_data(head1, head2);  // Compare the two numbers

                // Determine the sign based on comparison
                if (ret_value == 1)
                    sign = 0;
                else if (ret_value == 2)
                    sign = 1;
                else
                    sign = 0;

                // Perform subtraction based on the comparison result
                if (ret_value == 1)
                    subtraction(head1, tail1, head2, tail2, &result_head, &result_tail, 0);
                else if (ret_value == 0)
                    subtraction(head2, tail2, head1, tail1, &result_head, &result_tail, 1);
                else if (ret_value == 2)
                    printf("0\n");

                // Print the result
                temp = result_head;
                while (temp != NULL) {
                    printf("%d", temp->data);  // Print each digit of the result
                    temp = temp->next;
                }
                if (ret_value != 2)
                    printf("\n");
                break;

            case 'x':  // Multiplication case
                store_data(argv[1], &head1, &tail1);  // Store first number (argv[1]) in linked list
                store_data(argv[3], &head2, &tail2);  // Store second number (argv[3]) in linked list
                zero = multiplication_val(head1, head2);  // Check if multiplication is valid (no zero)
                
                if (zero) {
                    // Skip leading zeros in both numbers
                    while (head1->data < 1)
                        head1 = head1->next;
                    while (head2->data < 1)
                        head2 = head2->next;
                    
                    // Perform multiplication
                    multiplication(head1, tail1, head2, tail2, &result_head, &result_tail, sign);
                } else {
                    printf("0\n");  // If multiplication is invalid, print 0
                }

                // Print the result
                multiplication(head1, tail1, head2, tail2, &result_head, &result_tail, sign);
                while (result_head != NULL) {
                    printf("%d", result_head->data);  // Print each digit of the result
                    result_head = result_head->next;
                }
                printf("\n");
                break;

            case '/':  // Division case
                store_data(argv[1], &head1, &tail1);  // Store first number (argv[1]) in linked list
                store_data(argv[3], &head2, &tail2);  // Store second number (argv[3]) in linked list
                zero = division_val(head2);  // Check if division is valid (non-zero divisor)
                
                if (zero) {
                    // Skip leading zeros in both numbers
                    while (head1->data < 1)
                        head1 = head1->next;
                    while (head2->data < 1)
                        head2 = head2->next;
                    
                    ret_value = compare_data(head1, head2);  // Compare dividend and divisor
                    if (ret_value == 1) {
                        // Perform division
                        division(head1, tail1, head2, tail2, &result_head, &result_tail, sign);
                    } else if (ret_value == 2)
                        printf("1\n");  // If dividend equals divisor, result is 1
                    else  
                        printf("0\n");  // If dividend is smaller than divisor, result is 0
                } else {
                    printf("Undefined\n");  // Division by zero is undefined
                }
                break;

            default:  // Unsupported operator case
                printf("Unsupported operator\n");
        }
    } else {
        // Invalid input
        printf("Enter correct input\n");
    }

    return 0;
}
