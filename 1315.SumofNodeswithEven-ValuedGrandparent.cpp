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
    int count;

    void tra(TreeNode *node, int flag)
    {

        if (node == NULL)
        {
            return;
        }

        if (flag == 1)
        {
            tra(node->left, 2);
            tra(node->right, 2);
            return;
        }
        else if (flag == 2)
        {
            count += node->val;
            return;
        }

        if (!(node->val & 1))
        {
            tra(node->left, 1);
            tra(node->right, 1);
        }

        tra(node->left, flag);
        tra(node->right, flag);
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        count = 0;
        tra(root, 0);
        return count;
    }
};