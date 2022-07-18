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
    
    bool f(TreeNode* root, TreeNode* subRoot){
        
         if(root == NULL && subRoot == NULL){
            return true;
        }
        
         if(root == NULL || subRoot == NULL){
            return false;
        }
        
        if(root->val != subRoot->val){
            return false;
        }
        
        return f(root->left , subRoot->left) && f(root->right , subRoot->right);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
       if(root == NULL){
           return false;
       }
        
        bool k = false;
        if(root->val == subRoot->val){
           k =  f(root , subRoot);
        }
        
       return k || isSubtree(root->left , subRoot) ||  isSubtree(root->right , subRoot);
        
    }
};