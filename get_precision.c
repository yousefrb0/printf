#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string containing format specifiers.
 * @i: Index of the current character in the format string.
 * @list: List of arguments passed to _printf.
 *
 * Return: Precision value.
 */
int get_precision(const char *fm, int *i, va_list li)
{
    int _currunt_i = *i + 1;    // Initialize current index after '.'
    int precision = -1;     // Initialize precision to -1 (default)

    // Check if precision specifier exists
    if (fm[_currunt_i] != '.')
        return (precision);

    precision = 0; // Reset precision

    // Loop through characters after '.'
    for (_currunt_i += 1; fm[_currunt_i] != '\0'; _currunt_i++)
    {
        if (is_digit(fm[_currunt_i])) // If current character is a digit
        {
            precision *= 10;
            precision += fm[_currunt_i] - '0'; // Calculate precision value
        }
        else if (fm[_currunt_i] == '*') // If '*' character is encountered
        {
            _currunt_i++; // Move to the next character
            precision = va_arg(li, int); // Get precision from variable argument list
            break; // Exit loop after getting precision from '*'
        }
        else
            break; // Exit loop if an invalid character is encountered
    }

    *i = _currunt_i - 1; // Update the index to the last processed character

    return (precision); // Return the calculated precision
}

