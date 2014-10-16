class Solution
{
	public:
	bool isMatch(const char * s, const char *p)
	{
		char * star = NULL;
		char * ss = NULL;
		while (s[0] != '\0')
		{
			if (p[0] == '?')
			{
				s++;
				p++;
				continue;
			}
			if (s[0] == p[0])
			{
				s++;
				p++;
				continue;
			}
			if (p[0] == '*')
			{
				star = p;
				ss = s;
				p++;
				continue;
			}
			if (star != NULL)
			{
				p = star + 1;
				ss ++;
				s = ss;
			}
			break;
		}
		if (s[0] != '\0')
			return false;
		while (p[0] == '*')
			p++;
		if (p[0] != '\0')
			return false;
		return true;
	}
};
