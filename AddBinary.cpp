class Solution
{
	public:
	string addBinary (string a, string b)
	{
		string returnStr;
		int sizeA = a.size();
		int sizeB = b.size();
		int remainder = 0;
		for (int i = 0; i < sizeA || i < sizeB; i++)
		{
			int sum = remainder;
			if (i < sizeA)
				sum += a[sizeA - 1 - i] - '0';
			if (i < sizeB)
				sum += b[sizeB - 1 - i] - '0';
			returnStr = char(sum % 2 + '0') + returnStr;
			remainder = sum / 2;
		}
		if (remainder != 0)
			returnStr = char(remainder + '0') + returnStr;
		return returnStr;
	}
};
