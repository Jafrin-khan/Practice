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
        
        return max(h(root->left),h(root->right)) + 1;
    }
    
    int dia(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        return max({dia(root->left) , dia(root->right) , h(root->left) + h(root->right) + 1});
        
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        return dia(root)-1;
        
    }
};