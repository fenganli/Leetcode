bool equal(const vector<int> & T1, const vector<int> & T2)
{
    if (T1.size() != T2.size())
        return false;
    int size = T1.size();
    for (int i = 0; i < size; i++)
        if (T1[i] != T2[i])
            return false;
    return true;
}
bool cmp(const vector<int> & T1, const vector<int> & T2)
{
    int size = min(T1.size(), T2.size());
    for (int i = 0; i < size; i++)
        if (T1[i] < T2[i])
            return true;
        else if (T1[i] > T2[i])
            return false;
    return false;
}
class Solution
{
    vector<vector<int> > returnVec;
	vector<int> numbers;
	int goalNum;
	public:
	vector<vector<int> > combinationSum2(vector<int> & candidates, int target)
	{
		int size = candidates.size();
		if (size == 0)
			return returnVec;
		sort(candidates.begin(), candidates.end());
        size = candidates.size();
		for (int i = 0; i < size; i++)
			numbers.push_back(candidates[i]);
		goalNum = target;
		vector<int> searchVec;
		search(0, searchVec, 0);
 
		sort(returnVec.begin(), returnVec.end(), cmp);

		int curIndex = 0;
		int returnSize = returnVec.size();
		for (int i  = 1; i < returnSize; i++)
		    if (!equal(returnVec[curIndex], returnVec[i]))
		    {
		        returnVec[++curIndex] = returnVec[i];
		    }
        if (returnVec.size() != 0)
		    returnVec.resize(curIndex + 1);
		return returnVec;
	}
	void search(int index, vector<int> & vec, int sum)
	{
		if (sum == goalNum)
		{
			returnVec.push_back(vec);
			return;
		}
		else if (sum > goalNum || index == numbers.size())
			return;
		int size = numbers.size();
		for (int i = index; i < size; i++)
		{
			    vec.push_back(numbers[i]);
			    search(i + 1, vec, sum + numbers[i]);
			    vec.pop_back();
		}
		return;
	}
};
