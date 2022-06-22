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
    
    int h(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        return max(h(root->left) , h(root->right)) + 1;
    }
    
    int helper(TreeNode* root){
          
        if(root == NULL){
            return 0;
        }
        
        
        int currDia = h(root->left) + h(root->right) + 1;
        
        return max(currDia , max(helper(root->left) , helper(root->right)));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
      
        return helper(root) - 1;
    }
};