class Node
{
	public:
	string s;
	vector<vector<string> > path;
	Node (string x) : s(x) {}
};
class Solution
{
	public:
	vector<vector<string> >findLadders(string start, string end, unordered_set<string> & dict)
	{
		vector<vector<string> > returnVec;

		//corner case
		if (start == end)
		{
			vector<string> vec;
			vec.push_back(start);
			vec.push_back(end);
			returnVec.push_back(vec);
			return returnVec;
		}

		//initial condition
		vector<vector<Node> > map;
		vector<Node> vec;
		vec.push_back(Node(start));
		map.push_back(vec);
		int step = 0;
		bool terminal = false;

		while (!terminal)
		{
			vector<Node> vec = map[step];
			int size = vec.size();

			//got the end
			for (int i = 0; i < size; i++)
				if (diff(vec[i].s, end) == 1)
				{
					terminal = true;
					break;
				}

			//find the next round strings
			if (!terminal)
			{
				vector<Node> inputVec;
				for (int i = 0; i < size; i++)
				{
					string s = vec[i].s;
					int sSize = s.size();
					for (int j = 0; j < sSize; j++)
					{
						string inputStr = s;
						for (int k = 0; k < 26; k++)
							if (k + 'a' == int(s[j]))
								continue;
							else
							{
								inputStr[j] = (char)(k+'a');
								if (dict.find(inputStr) != dict.end())
								{
									inputVec.push_back(Node(inputStr));
									dict.erase(inputStr);
								}
							}
					}
				}
				int inputSize = inputVec.size();
				if (inputSize == 0)
					return returnVec;
				map.push_back(inputVec);
				step++;
			}
		}
		//try to recover the path right now
		for (int i = step; i >= 0; i--)
		{
			if (i == step)
			{
				vector<Node> & vec = map[i];
				int size = vec.size();
				for (int j = 0; j < size; j++)
				{
					Node &node = vec[j];
					vector<vector<string> > &path = node.path;
					if (diff(node.s, end) == 1)
					{
						vector<string> strVec;
						strVec.push_back(end);
						strVec.push_back(node.s);
						path.push_back(strVec);
					}
				}
			}
			else
			{
				vector<Node> &vec = map[i];
				vector<Node> &vec2 = map[i+1];
				int size1 = vec.size();
				int size2 = vec2.size();
				for (int j = 0; j < size2; j++)
				{
					Node node = vec2[j];
					if (node.path.size() == 0)
						continue;
					for (int k = 0; k < size1; k++)
						if (diff(vec[k].s, node.s) == 1)
						{
							vector<vector<string> > &path2 = node.path;
							vector<vector<string> > &path1 = vec[k].path;
							int sizePath = path2.size();
							for (int l = 0; l < sizePath; l++)
							{
								vector<string> singlePath = path2[l];
								singlePath.push_back(vec[k].s);
								path1.push_back(singlePath);
							}
						}
				}
			}
		}

		//we try to converse the path in map[0][0];
		Node strNode = map[0][0];
		int pathSize = strNode.path.size();
		for (int i = 0; i < pathSize; i++)
		{
			vector<string> vec;
			int pathLength = strNode.path[i].size();
			for (int j = pathLength - 1; j >= 0; j--)
				vec.push_back(strNode.path[i][j]);
			returnVec.push_back(vec);
		}
		return returnVec;
	}
	int diff(string s1, string s2)
	{
		int count = 0;
		int size = s1.size();
		for (int i = 0; i < size; i++)
			if (s1[i] != s2[i])
				count ++;
		return count;
	}
};
