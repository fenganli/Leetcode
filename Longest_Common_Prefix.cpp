class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		int size = strs.size();
		if (size == 0)
			return "";
		string longest_common_prefix = strs[0];
		for (int i = 1; i < size; i++)
			longest_common_prefix = getCommonPrefix(longest_common_prefix, strs[i]);
		return longest_common_prefix;
			

	}
	string getCommonPrefix(string & str1, string & str2)
	{
		string returnStr;
		int size1 = str1.size();
		int size2 = str2.size();
		for (int i = 0; i < size1 && i < size2; i++)
			if (str1[i] == str2[i])
				returnStr += str1[i];
			else
				break;
		return returnStr;
	}
};
