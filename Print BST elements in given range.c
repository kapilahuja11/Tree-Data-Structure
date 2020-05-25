struct Node{
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void printNearNodes(Node *root, int l, int h)
{
  if(root==NULL)
  return;
  if(l<root->data)
    printNearNodes(root->left,l,h);
  if ( l <= root->data && h >= root->data )  
        cout<<root->data<<" ";  
    if ( h > root->data )  
        printNearNodes(root->right, l, h);  
 }
