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
    vector<int> out;
    int maxlevel = 0;

    void dfs(TreeNode *it, int l)
    {

        if (l == maxlevel)
        {
            out.push_back(it->val);
            maxlevel++;
        }

        if (it->right)
        {
            dfs(it->right, l + 1);
        }
        if (it->left)
        {
            dfs(it = it->left, l + 1);
        }

        return;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        TreeNode *it = root;
        if (it)
            dfs(it, 0);

        return out;
    }
};