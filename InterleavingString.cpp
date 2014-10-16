class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int size1 = s1.size();
		int size2 = s2.size();
		int size3 = s3.size();
		if (size1 + size2 != size3)
			return false;
		if (size3 == 0)
			return true;
		if (size1 == 0)
		    return s2.compare(s3) == 0;
		if (size2 == 0)
		    return s1.compare(s3) == 0;
		char c = s3[0];
		int length1 = 0, length2 = 0, length3 = 0;
		for (int i = 0; i < size3; i++)
			if (s3[i] == c)
				length3++;
			else
			    break;
		for (int i = 0; i < size2; i++)
			if (s2[i] == c)
				length2++;
			else
			    break;
		for (int i = 0; i < size1; i++)
			if (s1[i] == c)
				length1++;
			else
			    break;
		if (length1 + length2 < length3 || (length3 < length1 && length3 < length2) )
			return false;
		if (length1 == 0)
		    return isInterleave(s1, s2.substr(length3, s2.npos), s3.substr(length3, s3.npos));
		else if (length2 == 0)
		    return isInterleave(s1.substr(length3, s1.npos), s2, s3.substr(length3, s3.npos));
		else
		{
		    if (length3 >= length1)
		        if (isInterleave(s1.substr(length1, s1.npos), s2.substr(length3 - length1, s2.npos), s3.substr(length3, s3.npos)))
                    return true;
		    if (length3 >= length2)
		        if (isInterleave(s1.substr(length3 - length2, s1.npos), s2.substr(length2, s2.npos), s3.substr(length3, s3.npos)))
                    return true;
		    return false;
		}
	}
};
