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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {

        queue<TreeNode *> q;
        stack<vector<int>> stac;
        int count;

        vector<vector<int>> out;
        if (!root)
        {
            return out;
        }

        q.push(root);
        count = 1;

        vector<int> level;
        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();
            level.push_back(temp->val);

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }

            count--;
            if (count == 0)
            {
                stac.push(level);
                level.clear();
                count = q.size();
            }
        }

        while (!stac.empty())
        {
            out.push_back(stac.top());
            stac.pop();
        }

        return out;
    }
};