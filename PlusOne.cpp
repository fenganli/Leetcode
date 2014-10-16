class Solution
{
	public:
	vector<int> plusOne(vector<int> &digits)
	{
		vector<int> retVec;
		int remainder = 1;
		int size = digits.size();
		int *result = new int[size];
		for (int i = size - 1; i >= 0; i--)
		{
			int sum = digits[i] + remainder;
			int append = sum % 10;
			remainder = sum / 10;
			result[i] = append;
		}
		if (remainder == 1)
			retVec.push_back(1);
		for (int i = 0; i < size; i++)
			retVec.push_back(result[i]);
		return retVec;
	}
};
