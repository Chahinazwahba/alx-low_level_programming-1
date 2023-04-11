#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words in
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
int i, count = 0;
for (i = 0; str[i] != '\0'; ++i)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
{
++count;
}
}
return (count);
}
/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
int i, j, k, len, count = 0;
char **words;
if (str == NULL || *str == '\0')
{
return (NULL);
}
count = count_words(str);
words = malloc((count + 1) * sizeof(char *));
if (words == NULL)
{
return (NULL);
}
for (i = 0, k = 0; i < count; ++i)
{
while (str[k] == ' ')
{
++k;
}
len = 0;
for (j = k; str[j] != '\0' && str[j] != ' '; ++j)
{
++len;
}
words[i] = malloc((len + 1) * sizeof(char));
if (words[i] == NULL)
{
for (--i; i >= 0; --i)
{
free(words[i]);
}
free(words);
return (NULL);
}
for (j = 0; j < len; ++j, ++k)
{
words[i][j] = str[k];
}
words[i][j] = '\0';
}
words[i] = NULL;
return (words);
}

