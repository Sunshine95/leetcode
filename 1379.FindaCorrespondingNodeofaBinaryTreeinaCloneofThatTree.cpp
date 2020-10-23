/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *tra(TreeNode *cloned, TreeNode *target)
    {

        if (cloned->val == target->val)
        {
            return cloned;
        }

        if (cloned->left)
        {
            TreeNode *l = tra(cloned->left, target);
            if (l)
                return l;
        }
        if (cloned->right)
        {
            TreeNode *r = tra(cloned->right, target);
            if (r)
                return r;
        }

        return NULL;
    }

    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        return tra(cloned, target);
    }
};