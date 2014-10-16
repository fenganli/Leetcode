class Solution
{
public:
	vector<int> findSubstring(string S, vector<string> &L)
	{
		vector<int> count = trimDuplicate(L);
		vector<int> matchIndex;
		int size = S.size();
		for (int i = 0; i < size; i++)
			matchIndex.push_back(-1);
		int lSize = L.size();
		for (int i  = 0; i < lSize; i++)
		{
			vector<int> vec = getMatch(S, L[i]);
			int vecSize = vec.size();
			for (int j = 0; j < vecSize; j++)
				matchIndex[vec[j]] = i;
		}
		vector<int> returnVec;
		int wordSize = L[0].size();
		int totalSize = 0;
		for (int i = 0; i < lSize; i++)
		    totalSize += count[i];
		int maxIndex = size - wordSize* totalSize;
		for (int i = 0; i <= maxIndex; i++)
			if (verify(i, matchIndex, size, totalSize, wordSize, count))
				returnVec.push_back(i);
		return returnVec;
	}
	vector<int> trimDuplicate(vector<string> & L)
	{
		sort(L.begin(), L.end());
		int curIndex = 0;
		vector<int> count;
		count.push_back(1);
		int lSize = L.size();
		for (int i = 1; i < lSize; i++)
		{
			if (L[i] == L[curIndex])
				count[curIndex] = count[curIndex] + 1;
			else
			{
				L[++curIndex] = L[i];
				count.push_back(1);
			}
		}
		L.resize(curIndex + 1);
		return count;
	}
	bool verify(int index, vector<int> & matchIndex, int sSize, int lSize, int wordSize, vector<int> &count)
	{
		vector<int> vec;
		for (int i = 0; i < lSize; i++)
			vec.push_back(0);
		for (int i = 0; i < lSize; i++)
		{
			if (index + wordSize * i >= sSize)
				return false;
			if (matchIndex[index + wordSize * i] == -1)
				return false;
			if (vec[matchIndex[index + wordSize * i]] == count[matchIndex[index + wordSize *i]])
				return false;
			vec[matchIndex[index + wordSize * i]] = vec[matchIndex[index + wordSize * i]] + 1;
		}
		return true;
	}
	vector<int> getMatch(string str, string str2)
	{
		vector<int> vec;
		int pos = 0;
		size_t found;
		do
		{
		    found = str.find(str2, pos);
			if (found != string::npos)
			{
				vec.push_back(found);
				pos = found + 1;
			}
		} while (found != string::npos);
		return vec;
	}
};
