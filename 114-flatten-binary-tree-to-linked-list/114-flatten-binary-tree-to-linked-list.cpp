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
    
    TreeNode* f(TreeNode* root){
        
        if(root == NULL|| (root->left == NULL && root->right == NULL)){
            return root;
        }
        
        root->left = f(root->left);
        root->right = f(root->right);
        
        TreeNode* temp = NULL;
        
        if(root->right){
            temp = root->right;
        }
        
        if(root->left){
            root->right = root->left;
            
             if(temp){
            
            TreeNode* traverse = root->right;
            while(traverse->right != NULL){
                traverse = traverse->right;
            }
            
            traverse->right = temp;
        }
         
        }
        
     
        
           root->left = NULL;
        
        return root;
    }
    void flatten(TreeNode* root) {
        
        f(root);
        
    }
};