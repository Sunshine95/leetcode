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
    int tra(TreeNode *root)
    {

        int l = root->left && tra(root->left);
        if (!l)
        {
            root->left = NULL;
        }

        int r = root->right && tra(root->right);
        if (!r)
        {
            root->right = NULL;
        }

        return l || r || root->val;
    }

    TreeNode *pruneTree(TreeNode *root)
    {

        int flag = tra(root);
        return flag ? root : nullptr;
    }
};