struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; 

Node *deleteNode(Node *root,  int x)
{
    Node *r,*temp;
    if(root==NULL)
    return root;
    else if(x < root->data)
    root->left=deleteNode(root->left,x);
    else if(x > root->data)
    root->right=deleteNode(root->right,x);
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            r=root;
            r=r->right;
            while(r->left!=NULL)
            r=r->left;
            
            root->data=r->data;
            root->right=deleteNode(root->right,root->data);
            
        }
        else
        {
            temp=root;
            if(root->left==NULL)
             root=root->right;
             else
             root=root->left;
        }
        return root;
    }
}
