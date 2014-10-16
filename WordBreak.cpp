class Solution
{
	public:
	bool wordBreak(string s, unordered_set<string> & dict)
	{
		int size = s.size();
		if (size == 0)
			return false;
		vector<bool> vec;
		for (int i = 0; i < size; i++)
			vec.push_back(false);
		vec.push_back(true);
		for (int i = size - 1; i >= 0; i--)
		{
			for (int j  = i + 1; j <= size; j++)
				if (dict.find(s.substr(i, j-i)) != dict.end() && vec[j])
					vec[i] = true;	
		}
		return vec[0];
	}
};
