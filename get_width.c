#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string containing format specifiers.
 * @i: Index of the current character in the format string.
 * @list: List of arguments passed to _printf.
 *
 * Return: Width value.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i; // Initialize current index after current character
    int width = 0; // Initialize width to 0

    // Loop through characters after the current index
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i])) // If current character is a digit
        {
            width *= 10; // Multiply the existing width by 10
            width += format[curr_i] - '0'; // Add the digit value to the width
        }
        else if (format[curr_i] == '*') // If '*' character is encountered
        {
            curr_i++; // Move to the next character
            width = va_arg(list, int); // Get width from variable argument list
            break; // Exit loop after getting width from '*'
        }
        else
            break; // Exit loop if an invalid character is encountered
    }

    *i = curr_i - 1; // Update the index to the last processed character

    return (width); // Return the calculated width
}

