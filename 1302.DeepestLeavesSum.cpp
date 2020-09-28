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
    int sum;
    int findMaxDepth(TreeNode *node, int depth)
    {

        int maxDepth = depth;
        if (node->left)
        {
            maxDepth = max(findMaxDepth(node->left, depth + 1), maxDepth);
        }
        if (node->right)
        {
            maxDepth = max(findMaxDepth(node->right, depth + 1), maxDepth);
        }

        return maxDepth;
    }

    void sumAtDepth(TreeNode *node, int depth, int target)
    {

        if (depth == target)
        {
            sum += node->val;
            return;
        }

        if (node->left)
        {
            sumAtDepth(node->left, depth + 1, target);
        }
        if (node->right)
        {
            sumAtDepth(node->right, depth + 1, target);
        }
    }

    int deepestLeavesSum(TreeNode *root)
    {

        int depth = findMaxDepth(root, 0);

        sum = 0;
        sumAtDepth(root, 0, depth);

        return sum;
    }
};