/** Definition for a binary tree node. **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    struct Branch
    {
        TreeNode *top;
        TreeNode *bottom;
        Branch() : top(nullptr), bottom(nullptr) {}
        Branch(TreeNode *top, TreeNode *bottom) : top(top), bottom(bottom) {}
    };

    void flatten(TreeNode *root)
    {

        if (!root)
            return;

        preorder(root);
    }

    Branch preorder(TreeNode *node)
    {

        TreeNode *right, *left, *top, *bottom;
        Branch next;

        top = node;
        left = node->left;
        right = node->right;
        node->left = nullptr;

        if (left)
        {
            next = preorder(left);
            node->right = next.top;
            node = next.bottom;
        }
        if (right)
        {
            next = preorder(right);
            node->right = next.top;
            node = next.bottom;
        }

        bottom = node;
        return Branch(top, bottom);
    }
};