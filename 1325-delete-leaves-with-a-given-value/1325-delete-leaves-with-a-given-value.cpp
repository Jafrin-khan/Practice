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
    SC = O(N)...stack space in dfs
    */
    
    TreeNode* f(TreeNode* root, int target){
        
        if(root == NULL) return NULL;
        root->left = f(root->left , target);
        root->right = f(root->right , target);
        if(root->left==NULL && root->right==NULL && root->val==target)return NULL;
        
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
          return f(root,target);   
    }

};