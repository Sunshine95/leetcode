/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (!root)
            return NULL;

        queue<Node *> q;
        q.push(root);
        Node *temp;
        int levelCount = 1;
        vector<Node *> level;

        while (!q.empty())
        {

            temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                level.push_back(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
                level.push_back(temp->right);
            }

            if (!--levelCount)
            {
                temp->next = NULL;
                for (int i = 1; i < level.size(); i++)
                {
                    (level[i - 1])->next = (level[i]);
                }
                level.clear();
                levelCount = q.size();
            }
        }

        return root;
    }
};