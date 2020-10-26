/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    vector<bool> visited;
    vector<Node *> copy_pointer;

    void dfs(Node *node, Node *copy_node)
    {

        visited[node->val] = true;
        copy_pointer[node->val] = copy_node;

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (!visited[node->neighbors[i]->val])
            {
                Node *t = new Node(node->neighbors[i]->val);
                copy_node->neighbors.push_back(t);

                dfs(node->neighbors[i], t);
            }
            else
            {
                copy_node->neighbors.push_back(copy_pointer[node->neighbors[i]->val]);
            }
        }
    }

    Node *cloneGraph(Node *node)
    {

        visited.resize(101, false);
        copy_pointer.resize(101, NULL);

        if (node == NULL)
            return NULL;

        Node *copy_node = new Node(node->val);
        dfs(node, copy_node);

        return copy_node;
    }
};