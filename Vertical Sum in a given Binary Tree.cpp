void vsumr(Node* root,int hd,map<int,int> &mp)
{
    if(root==NULL)
     return;
    vsumr(root->left,hd-1,mp);
    mp[hd]+=root->data;
    vsumr(root->right,hd+1,mp);
}
void verticalSum(Node *root) {
    // add code here.
    map<int,int> mp;
    map < int, int> :: iterator it; 
  
    vsumr(root,0,mp);
    for(it=mp.begin();it!=mp.end();it++)
     cout<<it->second<<" ";
}
