struct Node{
int data;
Node * right, * left;
};
/* The below function should return the node which is 
inorder successor of given node x. */
#include<vector>
void inorder(Node *root,vector<Node*> &v)
{
    if(root==NULL)
    return;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    vector<Node*> v;
    inorder(root,v);
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x && i!=v.size()-1)
        return v[i+1];
    }
    return NULL;
}
