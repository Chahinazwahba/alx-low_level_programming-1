#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words of
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
	int word_count = 0;
	int x = 0;

	while (str[x] != '\0')
	{
		if (str[x] != ' ' && (x == 0 || str[x - 1] == ' '))
		word_count++;

		x++;
	}

	return word_count;
}

/**
 * word_len - Calculates the length of the next word in a string
 * @str: The string to calculate the length of the next word of
 *
 * Return: The length of the next word in the string
 */
int word_len(char *str)
{
	int len = 0;
	int y = 0;

	while (str[y] != '\0' && str[y] != ' ')
	{
		len++;
		y++;
	}

	return len;
}
/**
 * free_words - Frees an array of words
 * @words: The array of words to free
 * @num_words: The number of words in the array
 *
 * Return: nothing
 */
void free_words(char **words, int num_words)
{
	int z;

	for (z = 0; z < num_words; z++)
	free(words[i]);

	free(words);
}

