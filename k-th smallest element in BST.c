struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};
#include <vector>
void inorder(Node *root,int k,vector<int> &vec)
{
    if(root==NULL)
    return;
    inorder(root->left,k,vec);
    vec.push_back(root->data);
    inorder(root->right,k,vec);
}
int KthSmallestElement(Node *root, int k)
{
    //add code here.
    vector<int> vec;
    inorder(root,k,vec);
    return vec[k-1];
}
