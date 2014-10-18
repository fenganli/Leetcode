class Solution
{
	public:
	int canCompleteCircuit(vector<int> & gas, vector<int> & cost)
	{
		int size = gas.size();
		if (size == 0)
			return -1;
		if (size == 1)
			if (cost[0] <= gas[0])
				return 0;
			else
				return -1;
		int sum = gas[0];
		int minNum = sum;
		int minIndex = 0;
		for (int i = 1; i < size; i++)
		{
			sum -= cost[i-1];
			if (sum <= minNum)
			{
				minNum = sum;
				minIndex = i;
			}
			sum += gas[i];
		}
		sum -= cost[size-1];
		if (sum >= 0)
			return minIndex;
		else
			return -1;

	}
};
