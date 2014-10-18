class Solution
{
	public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if (start == end)
			return 0;
		int size = dict.size();
		vector<string> vec;
		vec.push_back(start);
		int step = 0;
		while (true)
		{
			int size = vec.size();
			for (int i = 0; i < size; i++)
				if (diff(vec[i], end) == 1)
					return step + 2;
			vector<string> inputVec;
			for (int i = 0; i < size; i++)
			{
			    string s = vec[i];
			    int sSize = s.size();
			    for (int j = 0; j < sSize; j++)
			    {
			        string inputStr = s;
			        for (int k = 0; k < 26; k++)
			            if (k + 'a' == int(s[j]))
			                continue;
			            else
			            {
			                inputStr[j] = (char)(k+'a');
			                if (dict.find(inputStr) != dict.end())
			                {
			                     inputVec.push_back(inputStr);
			                     dict.erase(inputStr);
			                }
			            }
			    }
			}
			int inputSize = inputVec.size();
			if (inputSize == 0)
			    return 0;
			vec = inputVec;
			step++;
		}
	}
	int diff (string str1, string str2)
	{
		int count = 0;
		int size = str1.size();
		for (int i = 0; i < size; i++)
			if (str1[i] != str2[i])
				count++;
		return count;
	}		
};
