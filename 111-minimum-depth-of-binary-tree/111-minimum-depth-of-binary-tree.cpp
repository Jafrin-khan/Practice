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
    
    int mh(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int lh = mh(root->left);
        int rh = mh(root->right);
        
        return (lh == 0 || rh == 0 ) ? max(lh , rh) + 1 : min(lh,rh) +1;
    }
    int minDepth(TreeNode* root) {
        
        return mh(root);
        
    }
};