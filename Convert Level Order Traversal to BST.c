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
*/
// You are required to complete this function
Node* node(int k)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node *insert(Node *root,int k)
{
    if(root==NULL)
    return node(k);
    if(k<root->data)
    root->left=insert(root->left,k);
    else
    root->right=insert(root->right,k);
    return root;
}
Node* constructBst(int arr[], int n)
{
  struct Node* root=NULL;
  if(n==0)
  return NULL;
  for(int i=0;i<n;i++)
   root=insert(root,arr[i]);
  return root;
	
}
