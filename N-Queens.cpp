#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
	private:
		int * queenPosition;
		vector<vector<string> > returnVec;
		void search(int searchStep, int endStep)
		{
			if (searchStep == endStep)
			{
				vector<string> solutionVec;
				for (int i = 0; i < endStep; i++)
				{
					string lineStr = "";
					for (int j = 0; j < endStep; j++)
					{
						if (queenPosition[i] == j)
							lineStr += 'Q';
						else
							lineStr += '.';
					}
					solutionVec.push_back(lineStr);
				}
				returnVec.push_back(solutionVec);
				return;
			}
			for (int i = 0; i < endStep; i++)
			{
			  bool searchTag = true;
				for (int j = 0; j < searchStep; j++)
					if (queenPosition[j] == i || searchStep + i == j + queenPosition[j] || searchStep - j == i - queenPositona[j])
						searchTag = false;
				if (searchTag)
				{
					queenPosition[searchStep] = i;
					search(searchStep+1, endStep);
				}
			}
			return;
		}			
	public:
		vector<vector<string> > solveNQueens(int n)
		{
			queenPosition = new int[n];
			search(0, n);
			return returnVec;
		}
};
