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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {

        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }

        int level, nodes;
        queue<TreeNode *> q;

        q.push(root);
        level = 1, nodes = 1;

        while (level < depth - 1)
        {

            TreeNode *temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            nodes--;
            if (nodes == 0)
            {
                level++;
                nodes = q.size();
            }
        }

        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            TreeNode *left = temp->left, *right = temp->right;

            temp->left = new TreeNode(val, left, nullptr);
            temp->right = new TreeNode(val, nullptr, right);
        }

        return root;
    }
};