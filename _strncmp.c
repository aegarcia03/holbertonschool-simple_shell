#include "main.h"
/**
 * _strncmp - Compare two strings up to n characters
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if strings are equal up to n characters, negative if s1 is less
 *         than s2, positive if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned
						char)s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
