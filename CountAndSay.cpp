class Solution
{
	public:
	string countAndSay(int n)
	{
		string returnStr = "";
		if (n >= 1)
			returnStr = "1";
		for (int i = 2; i <= n; i++)
			returnStr = say(returnStr);
		return returnStr;
	}
	string say(string & str)
	{
		string returnStr = "";
		int size = str.size();
		int num = str[0] - '0', count = 1;
		for (int i = 1; i < size; i++)
		{
			if (str[i] - '0' == num)
				count++;
			else
			{
				returnStr += char(count + '0');
				returnStr += char(num + '0');
				num = str[i] - '0';
				count = 1;
			}
		}
		if (count != 0)
		{
			returnStr += char(count + '0');
			returnStr += char(num + '0');
		}
		return returnStr;
	}
};
