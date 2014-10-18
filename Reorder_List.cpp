#include <iostream>
using namespace std;
struct ListNode 
{
	int val;
	ListNode * next;
	ListNode (int x) : val(x), next(NULL) {}
};
class Solution
{
	public:
	void reorderList(ListNode * head)
	{
		if (head == NULL)
			return;
		int length = 0;
		ListNode * p = head;
		while (p != NULL)
		{
			length++;
			p = p -> next;
		}
		if (length == 1)
			return;
		int list2Index = (length + 1) / 2;
		p = head;
		int i = 0;
		while (i != list2Index - 1)
		{
			p = p -> next;
			i ++;
		}
		ListNode * head2 = p -> next;
		p -> next = NULL;
		/* below we try to reverse the second list
 	       						*/
		
		p = head2 -> next;
		head2 -> next = NULL;
		while (p != NULL)
		{
			ListNode * next = p -> next;
			p -> next = head2;
			head2 = p;
			p = next;
		}
	//	cout << head -> val << " " << head -> next -> val << " " << head -> next -> next << endl;
	//	cout << head2 -> val << " " << head2 -> next -> val << " " << head2 -> next -> next << endl;
		/* below we try to combine the two lists
 		*/
                	
		p = head;
		ListNode * p2 = head2;
		ListNode * combinedHead = NULL;
		ListNode * combinedP = NULL;
		while (p != NULL || p2 != NULL)
		{
			if (p != NULL)
				if (combinedHead == NULL)
				{
					combinedHead = p;
					combinedP = p;
					p = p -> next;
				}
				else
				{
					combinedP -> next = p;
					combinedP = p;
					p = p -> next;
				}
			if (p2 != NULL)
			{
				combinedP -> next = p2;
				combinedP = p2;
				p2 = p2 -> next;
			}
		}
		head = combinedHead; 
		
	}	
};
int main()
{
	Solution * solution = new Solution();
	ListNode * node1, * node2, * node3, * node4;
	node1 = new ListNode(1);
	node2 = new ListNode(2);
	node3 = new ListNode(3);
	node4 = new ListNode(4);
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = node4;
	solution -> reorderList(node1);
        return 0;
}
	
