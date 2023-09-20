#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void recur(TreeNode* root, vector<int> & preorder)
{
    if(root == NULL)
        return;

    preorder.push_back(root->data);
    recur(root->left, preorder);
    recur(root->right, preorder);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;

    recur(root, preorder);

    return preorder;
}