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

void recur(TreeNode* root, vector<int> & inorder)
{
    if(root == NULL)
        return;
    
    recur(root->left, inorder);
    inorder.push_back(root->data);
    recur(root->right, inorder);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    if(root == NULL)
        return inorder;
    
    recur(root, inorder);

    return inorder;
}