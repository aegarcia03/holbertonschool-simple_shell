#include <stdarg.h>
#include <limits.h>
#include "main.h"
#include <stddef.h>

/**
 * _snprintf - Custom implementation of snprintf
 * @str: The output string buffer
 * @size: The size of the output buffer
 * @format: The format string
 *
 * Return: The number of characters that would have been written if size
 * had been sufficiently large, not counting the terminating
 * null character
 */
int _snprintf(char *str, size_t size, const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *s;
	char c;

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			if (count < size - 1)
				str[count] = format[i];
			count++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						if (count < size - 1)
							str[count] = *s;
						count++;
						s++;
					}
					break;
				case 'c':
					c = (char)va_arg(args, int);
					if (count < size - 1)
						str[count] = c;
					count++;
					break;
				case '%':
					if (count < size - 1)
						str[count] = '%';
					count++;
					break;
				default:
					if (count < size - 1)
						str[count] = '%';
					count++;
					if (count < size - 1)
						str[count] = format[i];
					count++;
					break;
			}
		}
	}
	va_end(args);
	if (size > 0)
	{
		if (count < size)
			str[count] = '\0';
		else
			str[size - 1] = '\0';
	}
	return (count);
}
