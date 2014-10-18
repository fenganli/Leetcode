#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
	int minCut (string s)
	{
	    if (detectPalindrome(s))
	        return 0;
		int length = s.length();
		int * minNum = new int[length];
		minNum[0] = 0;
		for (int i = 1; i < length; i++)
		{
			int count = minNum[i-1] + 1;
			for (int j = 0; j < i; j++)
			{
			    if (s[j] != s[i])
			    {
				count = min(count, 1 + minNum[j-1]);
				break;
			    }
			    if (detectPalindrome(s.substr(j,i+1)))
					if (j == 0)
						count = min(count, 0);
					else
						count = min(count, 1 + minNum[j-1]);
			    if (count == 0)
			        break;
			}
			minNum[i] = count;
		}
		return minNum[length -1];
	}
	bool detectPalindrome(string s)
	{
		int length = s.length();
		for (int i = 0; i < length / 2; i++)
			if (s[i] != s[length - 1 - i])
				return false;
		return true;
	}
};
