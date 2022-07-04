int maxPathDown(TreeNode* root , int &maxi){
if(root == NULL){
return 0;
}
//compared with 0 to eliminate negative sums(like kadan's algo)
int leftSum = max(0,maxPathDown(root->left,maxi));
int rightSum =max(0,maxPathDown(root->right,maxi));
maxi = max(maxi,leftSum + rightSum + root->val);
return max(leftSum,rightSum) + root->val;
}
int maxPathSum(TreeNode* root) {
int maxi = INT_MIN;
maxPathDown(root,maxi);
return maxi;
}