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
    int kthSmallest(TreeNode *root, int k)
    {

        stack<TreeNode *> s;
        TreeNode *t = root;
        int ans;

        if (!root)
            return ans;

        while (!s.empty() || t)
        {

            if (t)
            {
                s.push(t);
                t = t->left;
            }
            else
            {
                t = s.top();
                s.pop();
                k--;
                ans = t->val;
                t = t->right;
            }

            if (!k)
                return ans;
        }

        return ans;
    }
};