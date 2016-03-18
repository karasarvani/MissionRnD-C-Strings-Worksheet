/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

int str_length(char *str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return index;
}
char removeSpaces(char *str) {
	int index = 0, count = 0, len;
	
	if (str)
	{
		len = str_length(str);
		while (str[index] != '\0')
		{
			if (str[index] == ' ')
			{
				count++;
				index++;
			}
			else if (count>0)
			{
				for (; str[index] != ' ';)
				{
					str[index - count] = str[index];
					str[index] = ' ';
					index++;
					if (str[index] == '\0')
						break;
				}
			}
			else
				index++;
		}
		str[len - count] = '\0';
	}
	else
		return '\0';
}
