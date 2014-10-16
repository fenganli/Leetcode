class Solution
{
	public:
	vector<string> generateParenthesis(int n)
	{
		return search(0, 0, 2 * n);
	}

	vector<string> search(int step, int count, int size)
	{
		vector<string> returnVec;
		if (count - (size - step) > 0)
			return returnVec;
		if (step == size && count == 0)
		{
			returnVec.push_back("");
			return returnVec;
		}
		if (count > 0)
		{
			vector<string> subVec = search(step + 1, count - 1, size);
			int subSize = subVec.size();
			for (int i  = 0; i < subSize; i++)
				returnVec.push_back(")" + subVec[i]);
		}
		vector<string> subVec = search(step + 1, count + 1, size);
		int subSize = subVec.size();
		for (int i = 0; i < subSize; i++)
			returnVec.push_back("(" + subVec[i]);
		return returnVec;
	}
};
