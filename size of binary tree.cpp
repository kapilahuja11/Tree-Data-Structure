int getsize(Node *root)
{
  if(root==NULL)
      return 0;
  else
      1+getsize(root->left)+getsize(root->right);
}
