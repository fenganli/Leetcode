class Solution
{
	vector<vector<int> > returnVec;
	vector<int> numbers;
	int goalNum;
	public:
	vector<vector<int> > combinationSum(vector<int> & candidates, int target)
	{
		int size = candidates.size();
		if (size == 0)
			return returnVec;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < size; i++)
			numbers.push_back(candidates[i]);
		goalNum = target;
		vector<int> searchVec;
		search(0, searchVec, 0);
		return returnVec;
	}
	void search(int index, vector<int> & vec, int sum)
	{
		if (sum == goalNum)
		{
			returnVec.push_back(vec);
			return;
		}
		else if (sum > goalNum)
			return;
		int size = numbers.size();
		for (int i = index; i < size; i++)
		{
			vec.push_back(numbers[i]);
			search(i, vec, sum + numbers[i]);
			vec.pop_back();
		}
		return;
	}
};
