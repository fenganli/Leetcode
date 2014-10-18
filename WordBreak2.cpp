#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Node
{
	public:
	bool end;
	Node ** next;
	Node ()
	{
		end = false;
		next = new Node *[26];
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}
	void setEnd(bool setValue)
	{
		end = setValue;
	}
	Node * getSetNext (int i)
	{
		if (next[i] == NULL)
			next[i] = new Node();
		return next[i];
	}
	Node * getNext(int i)
	{
		return next[i];
	}
	bool getEnd()
	{
		return end;
	}
	void insert (string s)
	{
		int length = s.length();
		if (length == 1)
		{
			setEnd(true);
			return;
		}
		else
			getSetNext(s[1] - 'a') -> insert(s.substr(1, s.npos));
	}
	bool find (string s)
	{
		int length = s.length();
		if (length == 1)
			return getEnd();
		else if (getNext(s[1] - 'a') == NULL)
			return false;
		else
			return getNext(s[1] - 'a') -> find(s.substr(1, s.npos));
	}
};
class Solution
{
	public:
		vector<string> search(string s, Node * root)
		{
			int length = s.length();
			if (length == 0)
			{
				vector <string> vec;
				vec.push_back("");
				return vec;
			}
			vector<int> index;
			Node * node = root;
			for (int i = 0; i < length; i++)
			{
				int charIndex = s[i] - 'a';
				if (node -> next[charIndex] == NULL)
					break;
				if ( (node -> next[charIndex]) -> getEnd() )
					index.push_back(i);
				node = node -> next[charIndex];
			}
			vector <string> vec;
			for (vector<int>::iterator iter = index.begin(); iter != index.end(); iter++)
			{
				string remainder = s.substr(0, *iter+1);
				string searchStr = s.substr(*iter + 1, s.npos);
				vector<string> searchResult = search(searchStr, root);
				for (vector<string>::iterator iter2 = searchResult.begin(); iter2 != searchResult.end(); iter2++)
				    if ((*iter2).length() != 0)
					    vec.push_back(remainder + " " + *iter2);
					else
					    vec.push_back(remainder);
			}
			return vec;
		}
		bool searchTree(char c, Node * root)
		{
		    bool found = false;
		    for (int i = 0; i < 26; i++)
		        if (root -> next[i] != NULL)
		          {
		              if (i == c-'a')
		                return true;
		              else if (searchTree(c, root -> next[i]))
		                found = true;
		              if (found)
		                return true;
		          }
		    return false;
		            
		}
		vector<string> wordBreak(string s, unordered_set<string> &dict)
		{
			Node * root = new Node();
			for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
				root -> insert (" " + *iter);
			int length = s.length();
			for (int i = 0; i < length; i++)
				if (!searchTree(s[i], root))
				{
					vector<string> vec;
					return vec;
				}
			return search(s, root);
		}
};
int main()
{
	return 0;
}
	
		
