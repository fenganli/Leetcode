#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int size1 = word1.size();
		int size2 = word2.size();
		vector<vector<int> > matrix;
		for (int i = 0; i <= size1; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= size2; j++)
				vec.push_back(0);
			matrix.push_back(vec);
		}
		for (int j = 0; j <= size2; j++)
			matrix[size1][j] = size2 - j;
		for (int j = 0; j <= size1; j++)
			matrix[j][size2] = size1 - j;
		for (int i = size1 - 1; i >= 0; i--)
			for (int j = size2 - 1; j >= 0; j--)
				if (word1[i] == word2[j])
					matrix[i][j] = matrix[i+1][j+1];
				else
					matrix[i][j] =min(matrix[i][j+1], min(matrix[i+1][j+1], matrix[i+1][j])) + 1;
/*		for (int i = 0;i <= size1; i++)
		{
			for (int j = 0; j <= size2; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}*/
		return matrix[0][0];	
		
	}
};
int main()
{
	Solution solution;
	solution.minDistance("park", "spake");
	return 0;
	
}
