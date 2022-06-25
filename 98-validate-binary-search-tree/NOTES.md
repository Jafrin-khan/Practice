class Solution {
public:
bool helper(TreeNode* root, TreeNode* max, TreeNode* min){
if(root == NULL){
return true;
}
if(max!=NULL){
if(root->val >= max->val){
return false;
}
}
if(min!=NULL){
if(root->val <= min->val){
return false;
}
}
if(!helper(root->left,root,min) || !helper(root->right,max,root)){
return false;
}
return true;
}
bool isValidBST(TreeNode* root) {
return helper(root, NULL, NULL);
}
};