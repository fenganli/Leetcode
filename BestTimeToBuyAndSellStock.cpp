class Solution
{
	public:
	int maxProfit(vector<int> & prices)
	{
		int size = prices.size();
		if (size < 2)
			return 0;
		int profit = 0;
		int * p1 = new int[size];
		int * p2 = new int[size];
		p1[0] = 0;
		int minNum = prices[0];
		for (int i = 1; i < size; i++)		
		{
			profit = max(profit, prices[i] - minNum);
			p1[i] = profit;
			minNum = min(minNum, prices[i]);
		}
		p2[size-1] = 0;
		profit = 0;
		int maxNum = prices[size-1];
		for (int i = size - 2; i >= 0; i--)
		{
			profit = max(profit, maxNum - prices[i]);
			p2[i] = profit;
			maxNum = max(maxNum, prices[i]);
		}
		profit = p2[0];
		for (int i = 2; i <= size - 2; i++)
			profit = max(profit, p1[i-1] + p2[i]);
		delete []p1;
		delete []p2;
		return profit;
	}
};
