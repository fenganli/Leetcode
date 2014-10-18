class Solution
{
    typedef long long int64;
	public:
	int sqrt(int x)
	{
		return search(x);
	}
	int search(int x)
	{
		int left = 0, right = min(x, 100000) + 1, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			int64 result = (int64) mid * (int64) mid;
			if (result == x)
			    return mid;
			else if (result < x)
		        left = mid + 1;
		    else
		        right = mid;
		    
		}
		if (left == 0)
			return 0;
		return left - 1;
	}
};
