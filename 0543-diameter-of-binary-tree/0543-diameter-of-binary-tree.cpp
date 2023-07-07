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
        if(root == NULL) return 0;
        
       int lh =  h(root->left);
       int rh = h(root->right);
        
       return 1 + max(lh,rh);
    }
    
    int f(TreeNode* root){
        
        if(root == NULL) return 0;
        return max({h(root->left) + h(root->right) + 1,f(root->left),f(root->right)});
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        return f(root)-1;
        
    }
};