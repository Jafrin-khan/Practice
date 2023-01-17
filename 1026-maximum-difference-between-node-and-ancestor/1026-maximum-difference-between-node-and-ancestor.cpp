/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    
    f(root->left , root->val);
    f(root->right , root->val);
    
    maxAncestorDiff(root->left);
    maxAncestorDiff(root->right);
    
    return maxi;
    
    }
};