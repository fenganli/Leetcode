class Solution
{
	public:
	double pow(double x, int n)
	{
		if (n == 0)
			return 1;
		else if (n == 1)
			return x;
		else if (x == 1)
			return 1;
		else if (x == -1)
		{
		    if (n % 2 == 0)
		        return 1;
		    else
		        return -1;
		}
		else if (n > 1)
			if (n % 2 == 0)
			{
				double k = pow(x, n / 2);
				return k * k;
			}
			else
			{
				double k = pow(x, n / 2);
				return x * k * k;
			}
		else if (n < 0)
			return 1 / pow(x, 0 - n);
	}
};