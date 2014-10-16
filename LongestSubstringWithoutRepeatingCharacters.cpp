class Solution
{
public:
	int lengthOfLongestSubstring (string s)
	{
		int size = s.size();
		if (size == 0)
			return 0;
		unordered_set<char> charSet;
		charSet.insert(s[0]);
		int leftIndex = 0, rightIndex = 1;
		int maxLength = 1;
		for (rightIndex; rightIndex < size; rightIndex++)
		{
			if (charSet.find(s[rightIndex]) != charSet.end())
			{
				maxLength = max(maxLength, rightIndex - leftIndex);
				for (int i = leftIndex; ;i++)
					if (s[i] != s[rightIndex])
						charSet.erase(s[i]);
					else
					{
						leftIndex = i + 1;
						break;
					}
			}
			else
				charSet.insert(s[rightIndex]);
		}
		maxLength = max(maxLength, (int)charSet.size());
		return maxLength;
	}
};