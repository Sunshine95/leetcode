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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {

        TreeNode *iti;

        while (true)
        {
            if (root && root->val < low)
            {
                root = root->right;
            }
            else if (root && root->val > high)
            {
                root = root->left;
            }
            else
            {
                break;
            }
        }

        iti = root;
        while (true)
        {
            while (iti->left && iti->left->val >= low)
            {
                iti = iti->left;
            }

            if (iti->left && iti->left->right)
            {
                iti->left = iti->left->right;
            }
            else
            {
                iti->left = NULL;
                break;
            }
        }

        iti = root;
        while (true)
        {
            while (iti->right && iti->right->val <= high)
            {
                iti = iti->right;
            }

            if (iti->right && iti->right->left)
            {
                iti->right = iti->right->left;
            }
            else
            {
                iti->right = NULL;
                break;
            }
        }

        return root;
    }
};