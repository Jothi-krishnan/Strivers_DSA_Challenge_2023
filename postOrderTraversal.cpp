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

void recur(TreeNode* root, vector<int> & postorder)
{
    if(root == NULL)
        return;

    recur(root->left, postorder);
    recur(root->right, postorder);
    postorder.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
   vector<int> postorder;

   recur(root, postorder);

   return postorder;
}