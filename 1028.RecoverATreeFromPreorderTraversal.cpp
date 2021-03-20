#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *root;
int preorder(string &s, int pos, int depth, TreeNode **node)
{
   
    if (pos >= s.size())
    {
        return pos;
    }

    int dash = 0, i;
    for (i = pos; s[i] == '-'; i++)
    {
        dash++;
    }
    string vv;
    for(; isdigit(s[i]); i++){
        vv += s[i];
    }
    if (dash == depth)
    {
        pos = i;
        int v = atoi(&vv[0]);
        cout << v;
        (*node) = new TreeNode(v);
        //cout << v << " add,node:" << &node << "\n";
        pos = preorder(s, pos, depth + 1, &((*node)->left));
        pos = preorder(s, pos, depth + 1, &((*node)->right));
    }

    return pos;
}

TreeNode *recoverFromPreorder(string S)
{
    int pos = preorder(S, 0, 0, &root);
    return root;
}

void print(TreeNode* tree){

    if(tree == NULL){
        cout << "NULL ";
        return;
    }

    cout << tree->val << " ";

    print(tree->left);
    print(tree->right);
}


int main(){

    string s;
    TreeNode* t;

    s = "1-2--3--4-5--6--7";
    t = recoverFromPreorder(s);
    cout << "\n";
    print(t);
    t = nullptr;

    s = "1-2--3---4-5--6---7";
    t = recoverFromPreorder(s);
    cout << "\n";
    print(t);
    t = nullptr;

    s = "1-401--349---90--88";
    t = recoverFromPreorder(s);
    cout << "\n";
    print(t);
    t = nullptr;

    return 0;
}