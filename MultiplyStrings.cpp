class Solution
{
	public:
	string multiply(string num1, string num2)
	{
		string result = "0";
		int size1 = num1.size();
		int size2 = num2.size();
		for (int i = 0; i < size2; i++)
		{
			int num = num2[i] - '0';
			string s = multiplySingle(num1, num);
			for (int j = 0; j < size2 - 1 - i; j++)
				s = s + '0';
			result = add(result, s);
		}
		while (result.size() != 1 && result[0] == '0')
			result = result.substr(1, result.npos);
		return result;
	}
	string multiplySingle(string num1, int num)
	{
		string result = "";
		int remainder = 0;
		int size1 = num1.size();
		for (int i = 0; i < size1; i++)
		{
			int sum = remainder;
			sum += (num1[size1-1-i] - '0') * num;
			result = char ('0' + sum % 10) + result;
			remainder = sum / 10;
		}
		if (remainder != 0)
			result = char ('0' + remainder) + result;
		return result;
	}
	string add(string num1, string num2)
	{
		int size1 = num1.size();
		int size2 = num2.size();
		int remainder = 0;
		string result = "";
		for (int i = 0; i < size1 || i < size2; i++)
		{
			int sum = remainder;
			if (i < size1)
				sum += (num1[size1-1-i] - '0');
			if (i < size2)
				sum += (num2[size2-1-i] - '0');
			result = char ('0' + sum % 10) + result;
			remainder = sum / 10;
		}
		if (remainder == 1)
			result = "1" + result;
		return result;
 }
};
