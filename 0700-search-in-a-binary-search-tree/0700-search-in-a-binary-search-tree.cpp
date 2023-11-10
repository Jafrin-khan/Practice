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
    
    void f(TreeNode* root, int data , TreeNode*& ans){
        
        if(root == NULL || ans != NULL) return;
        
        if(root->val == data){
            ans = root;
            return;
        }
        
        f(root->left , data , ans);
        f(root->right , data , ans);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode* ans = NULL;
        f(root , val , ans);
        
        return ans;
    }
};