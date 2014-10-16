class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> & num, int target)
    {
        sort(num.begin(), num.end());
        int size = num.size();
        vector<vector<int> > retVec;
        int memX, memY, memK;
        for (int i = 0; i < size - 3; i++)
        {
            if (i == 0)
                memX = num[i];
            else if (memX == num[i])
                continue;
            else
                memX = num[i];
            for (int j = i + 1; j < size - 2; j++)
            {
                if (j == i + 1)
                    memY = num[j];
                else if (memY == num[j])
                    continue;
                else
                    memY = num[j];
                for (int k = j + 1; k < size - 1; k++)
                {
                    if (k == j + 1)
                        memK = num[k];
                    else if (memK == num[k])
                        continue;
                    else
                        memK = num[k];
                    if (search(num, k + 1, size, target - num[i] - num[j] - num[k]))
                    {
                        vector<int> vec;
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[k]);
                        vec.push_back(target - num[i] - num[j] - num[k]);
                        retVec.push_back(vec);
                    }
                }
            }
        }
        return retVec;
    }
    bool search (vector<int> & num, int l, int r, int target)
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