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
    bool f(TreeNode* root , TreeNode* max , TreeNode* min){
        
        if(root == NULL){
            return true;
        }
        
        if((max != NULL && root->val >= max->val) || (min != NULL && root->val <= min->val)){
            return false;
        }
        
        return f(root->left , root , min) && f(root->right , max , root);
    }
    
    bool isValidBST(TreeNode* root) {
        
        return f(root , NULL , NULL); 
    }
};