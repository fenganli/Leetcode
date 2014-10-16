class HeadNode
{
private:
	ListNode * node;
	int listIndex;
public:
	HeadNode (ListNode * p, int x): node(p), listIndex(x) {}
	bool operator < (const HeadNode &headNode)
	{
		return node -> val > headNode.node -> val;
	}
	int getIndex()
	{
		return listIndex;
	}
	void setIndex(int x)
	{
		listIndex = x;
	}
	ListNode * getNode()
	{
		return node;
	}
	void setNode(ListNode * x)
	{
		node = x;
	}
};

class Solution
{
public:
	ListNode * mergeKLists(vector<ListNode *> &lists)
	{
		int size = lists.size();
		if (size == 0)
			return NULL;
		vector<HeadNode> vec;
		for (int i = 0; i < size; i++)
			if (lists[i] != NULL)
			{
				vec.push_back(HeadNode(lists[i], i));
				lists[i] = lists[i] -> next;
			}
		if (vec.size() == 0)
			return NULL;
		ListNode * newHead = NULL, * p = NULL;
		make_heap(vec.begin(), vec.end());
		while (vec.size() != 0)
		{
			HeadNode head = vec.front();
			pop_heap(vec.begin(), vec.end());
			vec.pop_back();
			if (newHead == NULL)
			{
				newHead = head.getNode();
				p = newHead;
			}
			else
			{
				p -> next = head.getNode();
				p = p -> next;
			}
			int index = head.getIndex();
			if (lists[index] != NULL)
			{
				vec.push_back(HeadNode(lists[index], index));
				push_heap(vec.begin(), vec.end());
				lists[index] = lists[index] -> next;
			}
		}
		p -> next = NULL;
		return newHead;
	}
};
