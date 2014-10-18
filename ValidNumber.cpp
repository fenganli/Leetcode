class Solution
{
	public:
	bool isNumber(const char *s)
	{
		char * newS  = trim(s);
		if (newS == NULL)
			return false;
		if (matchInt(newS))
			return true;
		if (matchDecimal(s))
			return true;
	}
	bool matchE(char * s)
	{
		int size = strlen(s);
		if (size == 0)
			return false;
		int i;
		for (i = 0; i < size; i++)
			if (s[i] == 'e')
				break;
		if (i == size)
			return false;
		s[i] = '\0';
		if ((matchInt(s) || matchDecimal(s)) && (matchInt(s+i+1) || matchDecimal(s+i+1)))
			return true;
		return false;
	}
	char * trim(char * s)
	{
		int size = strlen(s);
		if (size == 0)
			return NULL;
		int leftFlag = 0;
		int rightFlag = strlen(s) - 1;
		while (s[leftFlag] == ' ')
			leftFlag++;
		while (s[rightFlag] == ' ')
			rightFlag --;
		if (leftFlag > rightFlag)
			return NULL;
		s[rightFlag+1] = '\0';
		return s + leftFlag;
	}
	bool matchDecimal(char * s)
	{
		int size = strlen(s);
		if (size == 0)
			return false;
		if (s[0] == '0')
		{
			if (s[1] != '.')
				return false;
			else
			{
				for (int i = 2; i < size; i++)
				{
					int num = s[i] - '0';
					if (num < 0 || num > 9)
						return false;
				}
				return true;
			}
		}
		else
		{
			int num = s[0] - '0';
			if (num <= 0 || num > 9)
				return false;
			int i;
			for (i = 1; ; i++)
			{
				if (s[i] == '.')
					break;
				else
				{
					int num = s[i] - '0';
					if (num < 0 || num > 9)
						return false;
				}
			}
			for (i = i + 1; i < size; i++)
			{
				int num = s[i] - '0';
				if (num < 0 || num > 9)
					return false;
			}
			return true;
		}
	}
	bool matchInt(char * s)
	{
		int size = strlen(s);
		if (size == 0)
			return false;
		if (s[0] == '0')
		{
			if (size > 1)
				return false;
			else
				return true;
		}
		int num = s[0] - '0';
		if (num <= 0 || num > 9)
			return false;
		for (int i = 1; i < size; i++)
		{
			int num = s[i] - '0';
			if (num < 0 || num > 9)
				return false;
		}
		return true;
	}
};
