if(root->left)
{
root->left = removeLeafNodes(root->left,target);
}
if(root->right)
{
root->right = removeLeafNodes(root->right,target);
}
if(root->left==NULL && root->right==NULL && root->val==target)return NULL;
return root;