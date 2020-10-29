/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    long subSum(TreeNode *node)
    {

        if (node == NULL)
            return 0;

        long out = node->val;
        out += subSum(node->left);
        out += subSum(node->right);

        node->val = out;
        return out;
    }

    int maxProduct(TreeNode *root)
    {

        long total = subSum(root);
        queue<TreeNode *> q;

        long x, y, prod = 1;
        q.push(root);
        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            x = temp->val;
            y = total - temp->val;
            prod = max(prod, x * y);

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        return prod % 1000000007;
    }
};