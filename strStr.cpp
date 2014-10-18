class Solution {
public:
    char *strStr(char *haystack, char *needle) 
    {
        int hayLen = strlen(haystack);
        int neeLen = strlen(needle);
        if (neeLen == 0)
            return haystack;
	    for (int i = 0; i <= hayLen - neeLen; i++)
	    {
		    int j;
		    for (j = 0; haystack[i+j] != '\0' && needle[j] != '\0'; j++)
			    if (haystack[i+j] != needle[j])
				    break;
		    if (needle[j] == '\0')
			    return haystack + i;
	    }
	    return NULL;
    }
};
