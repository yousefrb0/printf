#include "main.h"

/* Function prototype */
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string.
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    /* Check for NULL format */
    if (format == NULL)
        return (-1);

    va_start(list, format);

    /* Loop through the format string */
    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%') // If not a format specifier
        {
            buffer[buff_ind++] = format[i]; // Store the character in the buffer
            if (buff_ind == BUFF_SIZE) // Check if buffer is full
                print_buffer(buffer, &buff_ind); // Print the buffer
            printed_chars++; // Increment the printed character count
        }
        else // If a format specifier is encountered
        {
            print_buffer(buffer, &buff_ind); // Print the buffer content
            flags = get_flags(format, &i); // Extract flags
            width = get_width(format, &i, list); // Extract width
            precision = get_precision(format, &i, list); // Extract precision
            size = get_size(format, &i); // Extract size
            ++i; // Move past the format specifier character
            printed = handle_print(format, &i, list, buffer,
                                   flags, width, precision, size); // Handle printing based on format
            if (printed == -1)
                return (-1); // Return -1 if an error occurred during printing
            printed_chars += printed; // Increment the printed character count
        }
    }

    print_buffer(buffer, &buff_ind); // Print any remaining buffer content

    va_end(list); // End variable argument list

    return (printed_chars); // Return the total number of printed characters
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind); // Print the contents of the buffer

    *buff_ind = 0; // Reset the buffer index
}

