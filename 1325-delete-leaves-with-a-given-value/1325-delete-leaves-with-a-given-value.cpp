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
    
    
    void f(TreeNode* root , int target){
        
        if(root == NULL){
            return;
        }
        
        f(root->left , target);
        f(root->right , target);
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->left && root->left->left == NULL && root->left->right == NULL && root->left->val == target){
            root->left = NULL;
        }
        
        if(root->right && root->right->left == NULL && root->right->right == NULL && root->right->val == target){
            root->right = NULL;
        }
        
       
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root == NULL){
            return NULL;
        }
        
        //us particular root k corresponding leaf nodes with specified target remove krenge
        f(root , target);
        
        if(root->left == NULL && root->right == NULL && root->val == target){
            return NULL;
        }
        
        //iteration maintain krenge kyunki f call k baad tree change hoga to dobara call krenge taaki jo ab leaf bn gayi nodes change krne k baad agr wo target k equal h to remove krenge unhe ab
        removeLeafNodes(root->left , target);
        removeLeafNodes(root->right , target);
        return root;
    }
};