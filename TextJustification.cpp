class Solution
{
	public:
	vector<string> fullJustify(vector<string> & words, int L)
	{
		vector<string> returnVec;
		int size = words.size();
		if (size == 0)
			return returnVec;
		int lineIndex = -1, lineLength = 0, index = 0;
		while (index != size)
		{
			if (lineIndex == -1)
			{
				lineIndex = index;
				lineLength = words[index].size();
				index++;
			}
			else // addding the word
			{
				if (lineLength + words[index].size() + 1 <= L) //just adding the word
				{
					lineLength = lineLength + words[index].size() + 1;
					index++;
				}
				else //we need to output the last string.
				{
					int wordNum = index - lineIndex;
					string output = "";
					if (wordNum == 1)
					{
						output = words[lineIndex];
						output += string(L-lineLength , ' ');
					}
					else
					{
						int extraSpace = (L - lineLength) / (wordNum - 1);
						int firstExtraSpace = (L - lineLength - extraSpace * (wordNum - 1));
						for (int i = 0; i < wordNum; i++)
						{
							if (i < firstExtraSpace)
							{
								output += words[lineIndex + i];
								output += string(extraSpace + 2, ' ');
							}
							else if (i != wordNum - 1)
							{
								output += words[lineIndex + i];
								output += string(extraSpace + 1, ' ');
							}
							else
								output += words[lineIndex + i];
						}
					}
					returnVec.push_back(output);
					lineIndex = index;
					lineLength = words[index].size();
					index++;
				}
			}
		}
		string output = "";
		for (int i = lineIndex; i < size; i++)
		{
			if (i == lineIndex)
				output += words[i];
			else
			{
				output += " ";
				output += words[i];
			}
		}
		output += string(L - output.size(), ' ');
		returnVec.push_back(output);
		return returnVec;
	}
};
