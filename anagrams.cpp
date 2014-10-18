class StrLabel
{
	private:
	string str;
	int index;
	public:
	StrLabel(string x, int y): str(x), index(y){}
	string getStr() const
	{
		return str;
	}
	int getIndex() const
	{
		return index;
	}
};
bool myLess(const StrLabel & t1, const StrLabel & t2)
{
	return t1.getStr() < t2.getStr();
}
class Solution
{
	public:
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> returnVec;
		int size = strs.size();
		if (size == 0)
			return returnVec;
		vector<StrLabel> vec;
		for (int i = 0; i < size; i++)
		{
			string str = strs[i];
			sort(str.begin(), str.end());
			vec.push_back(StrLabel(str, i));
		}
		sort(vec.begin(), vec.end(), myLess);
		StrLabel p("", 0);
		int count = 0;
		int vecSize = vec.size();
		for (int i = 0; i < vecSize; i++)
		{
			if (count == 0)
			{
				p = vec[i];
				count++;
			}
			else
			{
				if (p.getStr() == vec[i].getStr())
				{
					count++;
					returnVec.push_back(strs[vec[i].getIndex()]);
				}
				else
				{
					if (count != 1)
						returnVec.push_back(strs[p.getIndex()]);
					p = vec[i];
					count = 1;
				}
					
			}
		}
		if (count > 1)
			returnVec.push_back(strs[p.getIndex()]);
		return returnVec;
	}
};
