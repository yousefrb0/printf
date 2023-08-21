#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string containing format specifiers.
 * @i: Index of the current character in the format string.
 * @list: List of arguments passed to _printf.
 *
 * Return: Precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;    // Initialize current index after '.'
    int precision = -1;     // Initialize precision to -1 (default)

    // Check if precision specifier exists
    if (format[curr_i] != '.')
        return (precision);

    precision = 0; // Reset precision

    // Loop through characters after '.'
    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i])) // If current character is a digit
        {
            precision *= 10;
            precision += format[curr_i] - '0'; // Calculate precision value
        }
        else if (format[curr_i] == '*') // If '*' character is encountered
        {
            curr_i++; // Move to the next character
            precision = va_arg(list, int); // Get precision from variable argument list
            break; // Exit loop after getting precision from '*'
        }
        else
            break; // Exit loop if an invalid character is encountered
    }

    *i = curr_i - 1; // Update the index to the last processed character

    return (precision); // Return the calculated precision
}

