
class Solution
{
	public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode * node)
	{
		//corner case
		if (node == NULL)
			return NULL;
		stack<UndirectedGraphNode *> stack;
		
		//standard procedure for unvisited nodes before going into the stack
		UndirectedGraphNode * newNode = new UndirectedGraphNode (node -> label);
		(node -> neighbors).push_back(NULL);
		(node -> neighbors).push_back(newNode);
		stack.push(node);

		while (!stack.empty())
		{
			UndirectedGraphNode * node = stack.top();
			stack.pop();
			vector<UndirectedGraphNode*> & neighbors = node -> neighbors;
			int neighborSize = neighbors.size();
			UndirectedGraphNode * copyNode = neighbors[neighborSize - 1];
			for (int i = 0; i < neighborSize - 2; i++)
			{
				UndirectedGraphNode * linkNode = neighbors[i]; 
				vector<UndirectedGraphNode*> & vec = linkNode -> neighbors;
				if (vec.size() < 2 || vec[vec.size() - 2] != NULL) //judge whether this node has a copy
				{
					UndirectedGraphNode * newNode = new UndirectedGraphNode (linkNode -> label);
					(linkNode -> neighbors).push_back(NULL);
					(linkNode -> neighbors).push_back(newNode);
					stack.push(linkNode);
					(copyNode -> neighbors).push_back(newNode);

				}
				else
					(copyNode -> neighbors).push_back(vec[vec.size() - 1]);
			}
		}
		
		//below we recover the original graph
		//stack<UndirectedGraphNode * > rStack;
		//rStack.push(node);
		stack.push(node);
		while (!stack.empty())
		{
			UndirectedGraphNode * node = stack.top();
			stack.pop();
			vector<UndirectedGraphNode *> &neighbors = node -> neighbors;
			if (neighbors.size() >= 2 && neighbors[neighbors.size() - 2] == NULL)
			{
				neighbors.pop_back();
				neighbors.pop_back();
				int size = neighbors.size();
				for (int i = 0; i < size; i++)
					stack.push(neighbors[i]);
			}
		}
		return newNode;
	}
};
