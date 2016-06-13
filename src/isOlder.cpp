/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisons. You are free to write any helper functions.
*/
int check(char *st1, char *st2)
{
	int i,j,ch,count=0;
	for (i = 0, j = 0; st1[i] && st2[j]; i++, j++)
	{
		if (i == 2 || i == 5)
		{
			if (st1[i] == '-'&&st2[i] == '-')
				continue;
			else
				return -1;
		}
		if (st1[i] >= '0'&&st1[i] <= '9')
			continue;
		else
			return -1;
		if (st2[j] >= '0'&&st2[j] <= '9')
			continue;
		else
			return -1;
	}
	if (i == j&&j == 10);
	else
		return -1;
	if (st1[3] == '1'||st2[3]=='1')
	{
		if (st1[4] > '2'||st2[4]>'2')
		{
			return -1;
		}
	}
	if (st1[3]>'1' || st2[3]>'1')
	{
		return -1;
	}
	ch = ((st1[8] - '0') * 10 + (st1[9] - '0'));
	if (ch % 4 == 0)
		count = 1;
	ch = ((st1[3] - '0') * 10 + (st1[4] - '0'));
	switch (ch)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (st1[0] == '3'&&st1[1] > '0')
		{
			return -1;
		}
		break;
	case 2:
		if (count == 0)
		{
			if (st1[0] == '2'&&st1[1] > '8')
			{
				return -1;
			}
		}
		else
		{
			if (st1[0] > '2')
				return -1;
		}
		break;
	}
	return 0;
}
int compare(char a, char b)
{
	if (a == b)
		return 0;
	else if (a < b)
		return 1;
	else
		return 2;
}
int isOlder(char *dob1, char *dob2) {
	int equal = -1,ch,i;
	ch=check(dob1, dob2);
	if (ch == -1)
		return -1;
	for (i = 6; i < 10; i++)
	{
		equal=compare(dob1[i], dob2[i]);
		if (equal == 0)
			continue;
		else
			return equal;
	}
	equal = compare(dob1[4], dob2[4]);
	if (equal == 0)
	{
		equal = compare(dob1[3], dob2[3]);
		if (equal == 0)
		{
			equal = compare(dob1[1], dob2[1]);
			if (equal == 0)
			{
				equal = compare(dob1[0], dob2[0]);
				if (equal == 0)
					return 0;
				else
					return equal;
			}
			else
				return equal;
		}
		else
			return equal;
	}
	else
		return equal;
}
