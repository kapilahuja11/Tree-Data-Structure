struct Node{
  int data;
	Node *left, *right;
};
Node *construct(Node *root,int value)
{
    if(root==NULL)
    {
        Node *newnode=new Node;
        newnode->data=value;
        newnode->right=newnode->left=NULL;
        return newnode;
    }
    if(root->data>value)
    root->left=construct(root->left,value);
    if(root->data<value)
    root->right=construct(root->right,value);
    return root;
}
Node *constructTree (int post[], int size)
{
   Node *root=new Node;
   root->data=post[size-1];
   root->right=root->left=NULL;
   for(int i=size-2;i>=0;i--)
   {
       root=construct(root,post[i]);
   }
   return root;
}
