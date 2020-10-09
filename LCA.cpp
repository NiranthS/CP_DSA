Node *LCA(Node *root,Node *a,Node *b){
    Node *left,*right;
    if(root==NULL)
     return root;
    if(root==a||root==b)
       return root;
    left=LCA(root->left,a,b);
    right=LCA(root->right,a,b);
    if(left&&right)
        return root;
    else return (left?left:right);
}
  
