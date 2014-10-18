#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
	int maximalRectangle(vector<vector<char> > & matrix)
	{
		int size1 = matrix.size();
		if (size1 == 0)
			return 0;
		int size2 = matrix[0].size();
		if (size2 == 0)
			return 0;
		vector<vector<int> > height;
		for (int i = 0; i < size1; i++)
		{
			vector<int> vec;
			for (int j = 0; j <= size2; j++)
				vec.push_back(0);
			height.push_back(vec);
		}
		for (int i = 0; i < size1; i++)	
		{
			cout << endl;
			for (int j = 0; j < size2; j++)
			{
				if (i == 0)
					if (matrix[i][j] == '1')
						height[i][j] = 1;
					else
						height[i][j] = 0;
				else
					if (matrix[i][j] == '1')
						height[i][j] = height[i-1][j] + 1;
					else
						height[i][j] = 0;
				cout << height[i][j] << " ";
			}
		}
		int maxArea = 0;
		for (int i = 0; i < size1; i++)
		{
			stack<int> heightStack;
			for (int j = 0; j <= size2; j++)
			{
				while (!heightStack.empty() && height[i][j] <= height[i][heightStack.top()])
				{
					int index = heightStack.top();
					heightStack.pop();
					maxArea = max(maxArea, (j - index) * height[i][index]);
						
				}
				if (heightStack.empty())
				{
					height[i][0] = height[i][j];
					heightStack.push(0);
				}
				else
					heightStack.push(j);
			}
			
		}	
		return maxArea;
	}
};
int main()
{
	Solution solution;
	vector<vector<char> > inputVec;
	char myArray1[] = {'0', '1' , '1', '0', '1'};
	char myArray2[] = {'1', '1', '0', '1', '0'};
	char myArray3[] = {'0', '1', '1', '1', '0'};
	char myArray4[] = {'1', '1', '1', '1', '0'};
	char myArray5[] = {'1', '1', '1', '1', '1'};
	char myArray6[] = {'0', '0', '0', '0', '0'};
	vector<char> vec1(myArray1, myArray1 + 5);
	vector<char> vec2(myArray2, myArray2 + 5);
	vector<char> vec3(myArray3, myArray3 + 5);
	vector<char> vec4(myArray4, myArray4 + 5);
	vector<char> vec5(myArray5, myArray5 + 5);
	vector<char> vec6(myArray6, myArray6 + 5);
	inputVec.push_back(vec1);
	inputVec.push_back(vec2);
	inputVec.push_back(vec3);
	inputVec.push_back(vec4);
	inputVec.push_back(vec5);
	inputVec.push_back(vec6);
	solution.maximalRectangle(inputVec);
	return 0;
}
