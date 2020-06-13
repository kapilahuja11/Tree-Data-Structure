#include<vector>
vector<int> vec;
void inorder(struct Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    vec.push_back(root->data);
    inorder(root->right);
}
bool isBST(Node* root) {
    
    vec.clear();
    inorder(root);
    int s=vec.size();
    for(int i=1;i<s;i++)
    {
        if(vec[i]<vec[i-1])
        {
        return false;
        break;
        }
    }
    return true;
}
