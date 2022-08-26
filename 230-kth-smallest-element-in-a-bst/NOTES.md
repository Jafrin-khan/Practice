int ans;
void helper(TreeNode* root,int k,int& counter){
if(!root)
return;
if(counter>k)
return;
helper(root->left,k,counter);
counter++;
if(k == counter)
ans = root->val;
helper(root->right,k,counter);
}
int kthSmallest(TreeNode* root, int k) {
int counter = 0;
helper(root,k,counter);
return ans;
}