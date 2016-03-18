/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_rev(char *input, int left_ind, int right_ind)
{
	char temp;
	while (left_ind<right_ind)
	{
		temp = input[left_ind];
		input[left_ind] = input[right_ind];
		input[right_ind] = temp;
		left_ind++;
		right_ind--;
	}
}
void str_words_in_rev(char *input, int len){
	int count = 0, left_ind = 0, right_ind = len - 1, index = 0;
	str_rev(input, left_ind, right_ind);
	while (input[index] != '\0')
	{
		if (input[index] != ' ')
		{
			count++;
			index++;
		}
		else if (input[index] == ' ')
		{
			str_rev(input, index - count, index - 1);
			count = 0;
			index++;
		}
	}
	str_rev(input, index - count, index - 1);
}
