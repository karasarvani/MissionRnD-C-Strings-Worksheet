/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int find_word(char *str1, char *str3)
{

	int index = 0, index1 = 0, length = 0, index2, length_str = 0;
	for (index = 0; str3[index] != '\0'; index++)
		length++;
	for (index = 0; str1[index] != '\0'; index++)
		length_str++;

	index = 0;
	index2 = 0;
	for (; index2 <= length_str - length;)
	{
		if (str1[index] == str3[index1])
		{
			index++;
			index1++;
			if (str3[index1] == '\0')
			{
				return 1;
				break;
			}
		}
		else if (str1[index] != str3[index1])
		{
			index1 = 0;
			index2++;
			index = index2;
		}
	}
	return 0;

}

char ** commonWords(char *str1, char *str2) {
	int k = 0, i, m = 0, n = 0, j = 0, result;
	char str3[31];
	char **result_arr;
	result_arr = (char**)malloc(sizeof(char) * 31);
	if (!str1&&!str2)
		return NULL;
	for (i = 0;; i++)
	{
		if (str2[i] == ' ' || str2[i] == '\0')
		{
			str3[k] = '\0';
			result = find_word(str1, str3);
			k = 0;
			if (result == 1)
			{
				n = 0;
				result_arr[m] = (char*)malloc(sizeof(char) * 31);
				for (j = 0; str3[j] != '\0'; j++)
				{
					result_arr[m][n] = str3[j];
					n++;
				}
				result_arr[m][n] = '\0';
				m++;
			}
			if (str2[i] == '\0')
				break;
		}
		else
		{
			str3[k] = str2[i];
			k++;
		}
	}
	if (m == 0)
		return NULL;
	return  result_arr;
}
