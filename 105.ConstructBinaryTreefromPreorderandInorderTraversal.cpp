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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        if (preorder.empty())
            return NULL;

        TreeNode *root = new TreeNode();
        root->val = preorder[0];

        if (preorder.size() == 1)
            return root;
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), root->val);

        int l = it - inorder.begin();
        int r = inorder.end() - it;

        vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + l + 1);
        vector<int> inorderLeft(inorder.begin(), it);

        vector<int> preorderRight(preorder.begin() + l + 1, preorder.begin() + l + r);
        vector<int> inorderRight(it + 1, it + r);

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};