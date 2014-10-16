class Solution
{
	public:
	RandomListNode * copyRandomList(RandomListNode * head)
	{
		if (head == NULL)
			return NULL;
		map<RandomListNode *, RandomListNode *> pointerMap;
		RandomListNode * p = head;
		RandomListNode * newHead = NULL, * newP = NULL;
		while (p != NULL)
		{
			if (newHead == NULL)
			{
				newHead = new RandomListNode (p->label);
				newP = newHead;
			}
			else
			{
				newP -> next = new RandomListNode (p->label);
				newP = newP -> next;
			}
			pointerMap.insert(make_pair(p, newP));
			newP -> random = p -> random;
			p = p -> next;
		}
		newP -> next = NULL;
		newP = newHead;
		while (newP != NULL)
		{
			if (newP -> random != NULL)
				newP -> random = pointerMap.find(newP->random) -> second;
			newP = newP -> next;
		}
		return newHead;
	}
	int getIndex(RandomListNode * head, RandomListNode * target)
	{
		RandomListNode * p = head;
		int index = 0;
		while (p != NULL)
		{
			if (p == target)
				return index;
			index++;
			p = p->next;
		}
		return -1;
	}
	RandomListNode * getPointer(RandomListNode * head, int index)
	{
		if (index == -1)
			return NULL;
		RandomListNode * p = head;
		for (int i = 0; i < index; i++)
			p = p -> next;
		return p;
	}
};
