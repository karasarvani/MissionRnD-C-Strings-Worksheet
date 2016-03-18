/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int power2(int afterdecimal)
{
	int result = 1;
	if (afterdecimal == 0)
		return result;
	while (afterdecimal != 0)
	{
		result = result * 10;
		afterdecimal--;
	}
	return result;
}
void number_to_str(float number, char *str, int afterdecimal){
	int num, temp, count = 0, index, k, dot_position = 0;
	num = (int)(power2(afterdecimal)*number);
	if (number<0)
	{
		temp = -num;
		num = -num;
	}
	else
		temp = num;
	while (temp != 0)
	{
		count++;
		temp = temp / 10;
	}
	if (afterdecimal == 0)
	{
		if (number >= 0)
		{
			str[count] = '\0';
			index = count - 1;
			k = 0;
		}
		else
		{
			str[count + 1] = '\0';
			str[0] = '-';
			index = count;
			k = 1;
		}
	}
	else if (number >= 0)
	{
		str[count + 1] = '\0';
		index = count;
		k = 0;
		dot_position = count - afterdecimal;
	}
	else if (number<0)
	{
		str[0] = (char)'-';
		str[count + 2] = '\0';
		index = count + 1;
		k = 1;
		dot_position = count - afterdecimal + 1;
	}
	for (; index >= k; index--)
	{
		if (index == dot_position&&afterdecimal != 0)
			*(str + index) = '.';
		else
		{
			*(str + index) = (num % 10) + 48;
			num = num / 10;
		}
	}
}
