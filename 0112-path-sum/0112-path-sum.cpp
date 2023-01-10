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
    /*
    TC = O(N)
    SC = O(N)
    */
    bool f(TreeNode* root , int k){
        
        if(root == NULL){
            return false;
        }
      
        if(root->left == NULL && root->right == NULL){
            
            if(root->val == k){
                return true;
            }
            
            return false;
        }
        
        return f(root->left , k-root->val) || f(root->right , k-root->val);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL){
            return false;
        }
        return f(root , targetSum);
    }
};