int getmax(Node *root)
{
  if(root==NULL)
      return INT_MIN;
  else
      return MAX(root->key, MAX(getmax (root->left),getmax(root->right)));
