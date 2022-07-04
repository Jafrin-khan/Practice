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
    
    bool checkValidity(TreeNode* root , TreeNode* maxi , TreeNode* mini){
        
        if(root == NULL){
            return true;
        }
        
        if((maxi != NULL && root->val >= maxi->val) || (mini != NULL && root->val <= mini->val)){
            return false;
        }
        
        return checkValidity(root->left , root , mini) && checkValidity(root->right , maxi , root);
       
    }
    bool isValidBST(TreeNode* root) {
        
        return checkValidity(root , NULL , NULL);
    }
};