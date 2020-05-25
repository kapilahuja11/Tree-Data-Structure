struct Node{
    int key;
    Node *left, *right;
};
/*Complete the function below*/
#include <vector>
void inorder(Node *root,int k,vector<int> &vec)
{
    if(root==NULL)
    return;
    inorder(root->left,k,vec);
    vec.push_back(root->key);
    inorder(root->right,k,vec);
}
void kthLargest(Node *root, int k)
{
    //add code here.
    vector<int> vec;
    inorder(root,k,vec);
    int size=vec.size();
    cout<<vec[size-k]<<endl;
}
