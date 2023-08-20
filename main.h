#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/* Definition of the format structure */
typedef struct fmt {
    char fmt;                           // Format specifier
    int (*fn)(va_list, char[], int, int, int, int); // Function associated with the format
} fmt_t;

/* Declaration of the main printf function */
int _printf(const char *format, ...);

/* Function for handling printing based on format */
int handle_print(const char *fmt, int *i,
    va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
    int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
    int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

/* Utility function for converting numbers with specific sizes */
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

