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

/* Function should print common elements in given two trees */
#include<vector>

void inorder(struct Node *root,vector<int> &vec)
{
    if(root==NULL)
    return;
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}
void printCommon(Node *root1, Node *root2)
{
    vector<int> vec1,vec2;
     vec1.clear();
     vec2.clear();
     inorder(root1,vec1);
     inorder(root2,vec2);
     for(int i=0;i<vec1.size();i++)
     {
         for(int j=0;j<vec2.size();j++)
         {
             if(vec1[i]==vec2[j])
             {
             cout<<vec1[i]<<" ";
             }
         }
     }
     
}
