class Solution
{
	public:
	int maxArea(vector<int> &height)
	{
		int size = height.size();
		int maxArea = 0;
		int left = 0, right = size - 1;
		while (left < right)
		{
			if (height[left] == 0)
				left++;
			else if (height[right] == 0)
				right--;
			else if (height[left] <= height[right])
			{
				maxArea = max(maxArea, (right - left) * height[left]);
				left++;
			}
			else
			{
				maxArea = max(maxArea, (right - left) * height[right]);
				right--;
			}
		}
		return maxArea;
	}
};
