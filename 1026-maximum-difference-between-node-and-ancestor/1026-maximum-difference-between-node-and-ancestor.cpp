
class Solution {
public:
    int maxi = -1e9;
    void f(TreeNode* root ,  int value){
    
    if(root == NULL){
        return;
    }
    
    maxi = max(maxi ,abs(value- root->val));
    f(root->left , value);
    f(root->right , value);
}
    int maxAncestorDiff(TreeNode* root) {
         // Your code here 
    if(root == NULL){
        return -1e9;
    }
    
    f(root , root->val);
    
    maxAncestorDiff(root->left);
    maxAncestorDiff(root->right);
    
    return maxi;
    
    }
};