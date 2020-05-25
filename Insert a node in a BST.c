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
/* This function should insert a new node with 
  given data and return root of the modified tree  */
 // int datacheck(Node* q,int data);
Node* insert(Node* node, int data)
{
    if(node==NULL)
    {
        node=(Node*)malloc(sizeof(Node));
        node->data=data;
        node->left=node->right=NULL;
        return node;
    }
    else
    {
      if(data <node->data)
      node->left=insert(node->left,data);
      else if(data > node->data)
      node->right=insert(node->right,data);
      else
      return node;
    }
    
}
