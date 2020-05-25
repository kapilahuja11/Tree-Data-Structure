struct Node{
{
    int data;
    Node* left;
    Node* right;
}; 
/*Your code here*/
#include<vector>
void func1(Node *root,vector<int> &v)
{
    if(root==NULL)
    return;
    v.push_back(root->data);
    func1(root->left,v);
    func1(root->right,v);
}
void func2(Node *root,vector<int> &v,int &c)
{
    if(root==NULL)
    return;
    func2(root->left,v,c);
    root->data=v[c];
    c++;
    func2(root->right,v,c);
}
Node *binaryTreeToBST (Node *root)
{
   vector<int> v;
   func1(root,v);
   int c=0;
   sort(v.begin(),v.end());
   func2(root,v,c);
   return root;
}
 
