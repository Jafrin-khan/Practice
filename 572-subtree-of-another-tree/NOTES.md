bool check(TreeNode* root, TreeNode* subRoot){
if(root == NULL && subRoot == NULL){
return true;
}
if(root == NULL || subRoot == NULL){
return false;
}
if(root->val == subRoot->val){
return check(root->left,subRoot->left) && check(root->right,subRoot->right);
}
return false;
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
if(root == NULL){
return false;
}
bool k = false;
if(root->val == subRoot->val){
k = check(root,subRoot);
}
return k || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}