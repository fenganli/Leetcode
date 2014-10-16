class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int> &num)
		{
			sort(num.begin(), num.end());
			vector<vector<int> > retVec;
			int size = num.size();
			int memI, memY;
			for (int i = 0; i < size - 2; i++)
			{
				if (i == 0)
					memI = num[i];
				else if (memI == num[i])
						continue;
				else
						memI = num[i];
				for (int j = i + 1; j < size - 1; j++)
				{
					if (j == i + 1)
						memY = num[j];
					else if (memY == num[j])
						continue;
					else
						memY = num[j];
					if (search(num, j + 1, size, 0 - num[i] - num[j]))
					{
						vector<int> vec;
						vec.push_back(num[i]);
						vec.push_back(num[j]);
						vec.push_back(0 - num[i] - num[j]);
						retVec.push_back(vec);
					}
				}
			}
			return retVec;
		}
		bool search(vector<int> & vec, int l, int r, int target)
		{
			int left = l, right = r, mid;
			while (left < right)
			{
				mid = (left + right) / 2;
				if (num[mid] == target)
					return true;
				else if (num[mid] < target)
					left = mid + 1;
				else
					right = mid;
			}
			return false;
		}
};
