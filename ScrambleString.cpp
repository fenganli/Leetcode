class Solution
{
	public:
	bool isScramble(string s1, string s2)
	{
		int size = s1.size();
		if (size == 0)
			return true;
		if (s1 == s2)
			return true;
		string tempS1 = s1, tempS2 = s2;
		sort(tempS1.begin(), tempS1.end());
		sort(tempS2.begin(), tempS2.end());
		if (tempS1 != tempS2)
			return false;
		for (int i = 1; i < size; i++)
		{
			string subLeft1 = s1.substr(0, i);
			string subRight1 = s1.substr(i, size - i);
			if (isScramble(subLeft1, s2.substr(0,i)) && isScramble(subRight1, s2.substr(i, size -i)))
				return true;
			if (isScramble(subLeft1, s2.substr(size - i, i)) && isScramble(subRight1, s2.substr(0, size - i)))
				return true;
		}
		return false;
	}
};
