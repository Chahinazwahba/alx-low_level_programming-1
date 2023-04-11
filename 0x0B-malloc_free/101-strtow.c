#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count words in
 *
 * Return: The number of words in str
 */
int count_words(char *str)
{
    int i, count = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count++;
    }
    return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails
 */
char **strtow(char *str)
{
    int i, j, k, len, words;
    char **arr;

    if (str == NULL || str[0] == '\0')
        return (NULL);

    words = count_words(str);
    arr = malloc(sizeof(char *) * (words + 1));

    if (arr == NULL)
        return (NULL);

    for (i = 0, j = 0; i < words; i++)
    {
        while (str[j] == ' ')
            j++;

        len = 0;
        while (str[j + len] != ' ' && str[j + len] != '\0')
            len++;

        arr[i] = malloc(sizeof(char) * (len + 1));

        if (arr[i] == NULL)
        {
            for (k = 0; k < i; k++)
                free(arr[k]);
            free(arr);
            return (NULL);
        }

        for (k = 0; k < len; k++)
            arr[i][k] = str[j + k];

        arr[i][k] = '\0';
        j += len;
    }

    arr[i] = NULL;
    return (arr);
}
