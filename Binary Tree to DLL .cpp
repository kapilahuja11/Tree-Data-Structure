void bToDLL(Node *root, Node **head)
{
    if(root==NULL)
    return;
    static Node *prev =NULL;
    bToDLL(root->left,head);
    if(*head==NULL)
    {
     prev=NULL;    
    *head=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
        
    }
    prev=root;
    bToDLL(root->right,head);
}
