#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0, i;

	while (dest[dest_len])
		dest_len++;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}