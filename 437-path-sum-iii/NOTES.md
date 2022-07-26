int count = 0;
void f(TreeNode* root,long long sum , int targetSum){
if(root == NULL){
return;
}
sum += root->val;
if(sum == targetSum){
count++;
}
f(root->left , sum , targetSum);
f(root->right , sum , targetSum);
}
int pathSum(TreeNode* root, int targetSum) {
if(root == NULL){
return 0;
}
int sum = 0;
f(root , sum , targetSum);
pathSum(root->left , targetSum);
pathSum(root->right , targetSum);
return count;
}