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
    bool isValidBST(TreeNode *root)
    {

        if (!root)
        {
            return true;
        }

        stack<TreeNode *> s;
        vector<int> inorder;

        do
        {

            while (root)
            {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            inorder.push_back((s.top())->val);
            s.pop();

            root = root->right;

        } while (!s.empty() || root);

        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i] >= inorder[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};