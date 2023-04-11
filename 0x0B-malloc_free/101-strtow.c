#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to array of words, or NULL if failure
 */
 
int count_words(char *);
int word_len(char *);
void free_words(char **, int);
 
char **strtow(char *str)
{
	char **words;
	int x, y, z, len, word_count;

	if (str == NULL || *str == '\0')
	return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
	return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	return (NULL);

	x = 0;
	while (*str != '\0' && x < word_count)
	{
		while (*str == ' ')
		str++;
		len = word_len(str);
		words[x] = malloc((len + 1) * sizeof(char));
		if (words[x] == NULL)
		{
			free_words(words, x);
			return (NULL);
		}
		for (y = 0, z = 0; z < len; y++, z++)
		{
			while (str[y] == ' ')
			y++;
			words[x][z] = str[y];
		}
		words[x][z] = '\0';
		x++;
		str += len;
	}
	words[x] = NULL;
	return (words);
}
