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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        queue<TreeNode *> q;
        TreeNode *temp;
        vector<vector<int>> v;
        vector<int> row;
        int count = 1;
        int zigzag = 0;

        if (root == NULL)
        {
            return v;
        }

        q.push(root);

        row.push_back(root->val);

        v.push_back(row);
        row.clear();
        zigzag++;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                row.push_back(temp->left->val);
            }

            if (temp->right)
            {
                q.push(temp->right);
                row.push_back(temp->right->val);
            }

            if (--count == 0)
            {

                if (!row.empty())
                {

                    if ((zigzag % 2))
                    {
                        reverse(row.begin(), row.end());
                    }

                    v.push_back(row);
                    row.clear();
                    zigzag++;
                }

                count = q.size();
            }
        }
        return v;
    }
};