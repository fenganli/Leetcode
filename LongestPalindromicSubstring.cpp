class Pair
{
	int left, right;
	public:
	Pair(int x, int y) : left(x), right(y) {}
	int getLeft()
	{
		return left;
	}
	int getRight()
	{
		return right;
	}
	int getSize()
	{
		return right - left + 1;
	}
};
class Solution
{
	public:
	string longestPalindrome(string s)
	{
		int size = s.size();
		if (size == 0)
			return "";
		vector<Pair> vec1;
		vector<Pair> vec2;
		for (int i = 0; i < size; i++)
			vec1.push_back(Pair(i, i));
		for (int i = 0; i < size - 1; i++)
			if (s[i] == s[i+1])
				vec2.push_back(Pair(i, i+1));
		Pair node1(0, 0);
		Pair node2(0, 0);
		while (true)
		{
			if (vec1.size() + vec2.size() == 0)
				break;
			int size1  = vec1.size();
			if (size1 == 1)
				node1 = vec1[0];
			vector<Pair> tempVec1;
			for (int i = 0; i < size1; i++)
			{
				Pair node = vec1[i];
				int left = node.getLeft();
				int right = node.getRight();
				if (left > 0 && right < s.size() - 1 && s[left-1] == s[right+1])
					tempVec1.push_back(Pair(left-1, right+1));
			}
			vec1 = tempVec1;

			int size2 = vec2.size();
			if (size2 == 1)
				node2 = vec2[0];
			vector<Pair> tempVec2;
			for (int i = 0; i < size2; i++)
			{
				Pair node = vec2[i];
				int left = node.getLeft();
				int right = node.getRight();
				if (left > 0 && right < s.size() - 1 && s[left-1] == s[right+1])
					tempVec2.push_back(Pair(left-1, right+1));
			}
			vec2 = tempVec2;
		}
		if (node1.getSize() > node2.getSize())
			return s.substr(node1.getLeft(), node1.getSize());
		else
			return s.substr(node2.getLeft(), node2.getSize());
	}
};
