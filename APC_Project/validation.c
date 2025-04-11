#include "ll.h"

void validation(char **str1 , char **str2, char **str3, int *sign)
{
    // Check if the operator is '-'
    if(*str2[0] == '-')
    {
	// Case when both operands are negative
	if(*str1[0] == '-' && *str3[0] == '-')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive ('0' represents positive)
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return;
	}
	// Case when both operands are positive
	else if(*str1[0] == '+' && *str3[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 1;    // Set the result to negative
	    return;
	}
	// Case when first operand is negative and second operand is positive
	else if(*str1[0] == '-' && *str3[0] == '+')
	{
	    *str2[0] = '+';  // Change operator to '+'
	    *str1[0] = 48;   // Set first operand's sign to positive
	    *str3[0] = 48;   // Set second operand's sign to positive
	    *sign = 1;     // Set the result to negative
	    return;
	}
	// Case when first operand is positive and second operand is negative
	else if(*str1[0] == '+' && *str3[0] == '-')
	{
	    *str2[0] = '+';  // Change operator to '+'
	    *str1[0] = 48;   // Set first operand's sign to positive
	    *str3[0] = 48;   // Set second operand's sign to positive
	    *sign = 0;     // Set the result to positive
	    return;
	}
	// Case when only first operand is negative
	else if(*str1[0] == '-')
	{
	    *str2[0] = '+';  // Change operator to '+'
	    *str1[0] = 48;   // Set first operand's sign to positive
	    *sign = 1;     // Set the result to negative
	    return;
	}
	// Case when only second operand is negative
	else if(*str3[0] == '-')
	{
	    *str2[0] = '+';  // Change operator to '+'
	    *str3[0] = 48;   // Set second operand's sign to positive
	    *sign = 0;     // Set the result to positive
	    return;
	}
	// Case when both operands are positive
	else if(*str1[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *sign = 1;    // Set the result to negative
	    return;
	}
	else if(*str3[0] == '+')
	{
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 1;    // Set the result to negative
	    return;
	}
	else
	{
	    *sign = 1;    // Set the result to negative
	    return;
	}
    }
    // Check if the operator is '+'
    else if(*str2[0] == '+')
    {
	// Case when both operands are positive
	if(*str1[0] == '+' && *str3[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return ;
	}
	// Case when both operands are negative
	else if(*str1[0] == '-' && *str3[0] == '-')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 1;    // Set the result to negative
	    return;
	}
	// Case when first operand is negative
	else if(*str1[0] == '-')
	{
	    *str1[0] = 48;   // Set first operand's sign to positive
	    *str2[0] = '-';  // Change operator to negative
	    *sign = 0;     // Set the result to positive
	    return;
	}
	// Case when first operand is positive and second operand is negative
	else if(*str1[0] == '+' && *str3[0] == '-')
	{
	    *str1[0] = 48;   // Set first operand's sign to positive
	    *str3[0] = 48;   // Set second operand's sign to positive
	    *str2[0] = '-';  // Change operator to negative
	    *sign = 1;     // Set the result to negative
	    return;
	}
	// Case when second operand is negative
	else if(*str3[0] == '-')
	{
	    *str3[0] = 48;   // Set second operand's sign to positive
	    *str2[0] = '-';  // Change operator to negative
	    *sign = 1;     // Set the result to negative
	    return;
	}
	else
	{
	    *sign = 0;     // Set the result to positive
	    return;
	}
    }
    // Check if the operator is '/'
    else if(*str2[0] == '/')
    {
	// Case when both operands are negative
	if(*str1[0] == '-' && *str3[0] == '-')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return;
	}
	// Case when either operand is negative
	else if(*str1[0] == '-' || *str3[0] == '-')
	{
	    if(*str1[0] == '-')
		*str1[0] = 48;  // Set first operand's sign to positive
	    else
		*str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 1;       // Set the result to negative
	    return;
	}
	// Case when both operands are positive
	else if(*str1[0] == '+' && *str3[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48; // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return;
	}
	// Case when first operand is positive
	else if(*str1[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    sign = 0;     // Set the result to positive
	    return;
	}
	// Case when second operand is positive
	else if(*str3[0] == '+')
	{
	    *str3[0] = 48;  // Set second operand's sign to positive
	    sign = 0;     // Set the result to positive
	    return;
	}
	else
	{
	    *sign = 0;    // Set the result to positive
	    return;
	}
    }
    // Check if the operator is 'x'
    else if(*str2[0] == 'x')
    {
	// Case when both operands are negative
	if(*str1[0] == '-' && *str3[0] == '-')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return;
	}
	// Case when either operand is negative
	else if(*str1[0] == '-' || *str3[0] == '-')
	{
	    if(*str1[0] == '-')
		*str1[0] = 48;  // Set first operand's sign to positive
	    else
		*str3[0] = 48;  // Set second operand's sign to positive
	    *sign = 1;       // Set the result to negative
	    return;
	}
	// Case when both operands are positive
	else if(*str1[0] == '+' && *str3[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    *str3[0] = 48; // Set second operand's sign to positive
	    *sign = 0;    // Set the result to positive
	    return;
	}
	// Case when first operand is positive
	else if(*str1[0] == '+')
	{
	    *str1[0] = 48;  // Set first operand's sign to positive
	    sign = 0;     // Set the result to positive
	    return;
	}
	// Case when second operand is positive
	else if(*str3[0] == '+')
	{
	    *str3[0] = 48;  // Set second operand's sign to positive
	    sign = 0;     // Set the result to positive
	    return;
	}
	else
	{
	    *sign = 0;    // Set the result to positive
	    return;
	}
    }
}

int validation_alpa(char *str , char *str1)
{
    int i = 0;

    // Check if the first character of str is '+' or '-', 
    // if so, set i to 1 to skip the sign character when checking the digits
    if(str[0] == '+' || str[0] == '-')
        i = 1;
    
    // Loop through the string str to check if all characters are digits
    while(str[i] != '\0')  // Continue until the end of the string
    {
        // Check if the character is a digit between '0' and '9'
        if(str[i] >= '0' && str[i] <= '9')
            i++;  // Move to the next character if it is a digit
        else  // If a non-digit character is found, return 0 (invalid input)
            return 0;
    }

    // Check if the first character of str1 is '+' or '-', 
    // if so, set i to 1 to skip the sign character when checking the digits
    if(str1[0] == '+' || str1[0] == '-')
        i = 1;
    else  // Otherwise, start checking from the first character of str1
        i = 0;

    // Loop through the string str1 to check if all characters are digits
    while(str1[i] != '\0')  // Continue until the end of the string
    {
        // Check if the character is a digit between '0' and '9'
        if(str1[i] >= '0' && str1[i] <= '9')
            i++;  // Move to the next character if it is a digit
        else  // If a non-digit character is found, return 0 (invalid input)
            return 0;
    }

    // If both strings only contain digits (with optional '+' or '-' at the start), return 1
    return 1;
}
