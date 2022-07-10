int f(TreeNode* root , int &maxi){
if(root == NULL){
return 0;
}
int leftSum = max(0 , f(root->left , maxi));
int rightSum = max(0 ,f(root->right , maxi));
maxi = max(maxi , leftSum + rightSum + root->val);
return max(leftSum , rightSum) + root->val;
}
int maxPathSum(TreeNode* root) {
int maxi = INT_MIN;
f(root , maxi);
return maxi;
}