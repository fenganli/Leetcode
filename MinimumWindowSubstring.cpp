class StringMap
{
	int array[256];
public:
	StringMap()
	{
		for (int i = 0; i < 256; i++)
			array[i] = 0;
	}
	StringMap(string s)
	{
		int size = s.size();
		for (int i = 0; i < 256; i++)
			array[i] = 0;
		for (int i = 0; i <  size; i++)
			addC(s[i]);
	}
	bool operator >=  (const StringMap T)
	{
		for (int i = 0; i < 256; i++)
			if (array[i] < T.array[i])
				return false;
		return true;
	}
	void addC(char c)
	{
		array[int (c)] ++;
	}
	void removeC(char c)
	{
		array[int (c)] --;
	}
};
class Solution
{
public:
	string minWindow(string S, string T)
	{
		StringMap tMap(T);
		StringMap sMap(S);
		if (!(sMap >= tMap))
			return "";
		int size = S.size();
		StringMap curMap;
		int leftIndex, rightIndex;
		for (int i = size - 1; i >= 0; i--)
		{
			curMap.addC(S[i]);
			if (curMap >= tMap)
			{
				leftIndex = i;
				break;
			}
		}
		for (int j = size - 1; ;j--)
		{
			curMap.removeC(S[j]);
			if (!(curMap >= tMap))
			{
				curMap.addC(S[j]);
				rightIndex = j;
				break;
			}
		}
		int minSize = rightIndex - leftIndex + 1, minLeft = leftIndex;
		for (int i = leftIndex - 1; i >= 0; i--)
		{
			if (S[i] != S[rightIndex])
			{
				leftIndex = i;
				curMap.addC(S[i]);
				continue;
			}
			else
			{
				leftIndex = i;
				rightIndex = rightIndex - 1;
				while (true)
				{
					curMap.removeC(S[rightIndex]);
					if (!(curMap >= tMap))
					{
						curMap.addC(S[rightIndex]);
						break;
					}
					else
						rightIndex--;
				}
				if (rightIndex - leftIndex + 1 < minSize)
				{
					minSize = rightIndex - leftIndex + 1;
					minLeft = leftIndex;
				}
			}
		}
		return S.substr(minLeft, minSize);
	}
};