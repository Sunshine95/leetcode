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
    int dfs(TreeNode *root, int depth)
    {

        if (root == NULL)
            return depth - 1;

        return max(dfs(root->left, depth + 1), dfs(root->right, depth + 1));
    }

    TreeNode *lca(TreeNode *root, int depth, int maxDepth)
    {

        if (root == NULL)
            return root;

        if (depth == maxDepth)
            return root;

        TreeNode *left = lca(root->left, depth + 1, maxDepth);
        TreeNode *right = lca(root->right, depth + 1, maxDepth);

        if (left && right)
            return root;

        return left != NULL ? left : right;
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {

        int maxDepth = dfs(root, 0);
        return lca(root, 0, maxDepth);
    }
};