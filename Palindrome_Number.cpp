class Solution
{
public:
	bool isPalindrome (int x)
	{
		if (x < 0)
			return false;
		int div = 1;
		int tempX = x;
		while (tempX >= 10)
		{
			tempX /= 10;
			div = div * 10;
		}
		while (x != 0)
		{
			int l = x / div;
			int r = x % 10;
			if (l != r)
				return false;
			x = x - l * div;
			x = x / 10;
			div = div / 100;
		}
		return true;
		
	}
};
