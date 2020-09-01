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
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        TreeNode *t = root;
        queue<TreeNode *> q;
        vector<int> level;
        vector<vector<int>> tree;
        int count;

        if (!root)
        {
            return tree;
        }

        level.push_back(t->val);
        tree.push_back(level);
        level.clear();

        q.push(t);
        count = q.size();

        while (!q.empty())
        {

            t = q.front();
            q.pop();

            if (t->left)
            {
                q.push(t->left);
                level.push_back(t->left->val);
            }

            if (t->right)
            {
                q.push(t->right);
                level.push_back(t->right->val);
            }

            if (--count == 0)
            {

                if (!level.empty())
                    tree.push_back(level);
                level.clear();
                count = q.size();
            }
        }

        return tree;
    }
};