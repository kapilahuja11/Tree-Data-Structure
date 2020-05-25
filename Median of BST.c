struct Node
{
	int data;
	struct Node *left, *right;
};
// your task is to complete the Function
// Note: Function should return median of the BST
#include<vector>
#include<queue>
vector<int> vec;
void inorder(struct Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    if(root!=NULL)
    vec.push_back(root->data);
    inorder(root->right);
}
float findMedian(struct Node *root,int n)
{
     float median;
     vec.clear();
      inorder(root);
      int size=vec.size();
      if(size%2==0)
      {
         int k=size/2;
         int h=vec[k]+vec[k-1];
         median=h/2.0;
          
      }
      else if(size%2==1)
      {
          int f=size/2;
          median=vec[f];
      }
      return median;
}
