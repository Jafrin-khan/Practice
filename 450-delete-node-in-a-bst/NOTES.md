if(!root)   return NULL;
if(root->val == key){
if(!root->left) return root->right;
if(!root->right)    return root->left;
TreeNode* temp = root->left;
TreeNode* ans = root->right;
root = root->right;
while(root->left)   root = root->left;
root->left = temp;
return ans;
}
if(key < root->val) root->left = deleteNode(root->left, key);
if(key > root->val) root->right = deleteNode(root->right, key);
return root;