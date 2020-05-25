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

/*You are required to complete this method*/
bool search(Node* root, int x)
{
    
     if (root == NULL) 
        return false; 
  
    if (root->data == x) 
        return true; 
    bool root1 = search(root->left,x); 
    bool root2 = search(root->right, x); 
  
    return root1 || root2; 
}
