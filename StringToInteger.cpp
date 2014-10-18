class Solution
{
	public:
	int atoi(const char * str)
	{
		typedef long long int int64;
		int64 result = 0;
		int i;
		bool positive = true;
		for (i = 0; ; i++)
		{
			if (str[i] != ' ')
				break;
		}
		if (str[i] == '+')
		{
			i++;
		}
		else if (str[i] == '-')
		{
			positive = false;
			i++;
		}
		int num = str[i] - '0';
		if (num < 0 || num > 9)
			return 0;
		for ( ; ; i++)
		{
			int num = str[i] - '0';
			if (num < 0 || num > 9)
				break;
			else
				result = result * 10 + num;
		}
		if (!positive)
			result = 0 - result;
		if (result > 2147483647)
			return 2147483647;
		else if (result < -2147483648)
			return -2147483648;
		else
		    return result;
	}
};
