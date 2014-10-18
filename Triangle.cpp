#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
	int minimumTotal(vector<vector<int> >&triangle)
	{
		int size = triangle.size();
		vector <int> minVec = triangle[size-1];
		for (int i = size - 2; i >= 0; i--)
		{
			vector<int> vec;
			for (int j = 0; j < i + 1; j++)
				vec.push_back((int)min(minVec[j], minVec[j+1]) + triange[i][j]);
			minVec = vec;
		}
		return minVec[0];
	}
};
		
