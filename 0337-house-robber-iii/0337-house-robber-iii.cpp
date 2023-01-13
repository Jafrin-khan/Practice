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
   Memoised
   
Time Complexity : O(N), we calculate dp[node] for each of N nodes in the tree only once.
Space Complexity : O(N), required for maintaining dp

    */
     unordered_map<TreeNode* , int> dp;
    int rob(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
       
        
        if(dp.count(root)){
            return dp[root];
        }
        int canRob = root->val;
        int dontRob = 0;
        
        if(root->left){
            canRob += rob(root->left->left) + rob(root->left->right);
            dontRob += rob(root->left);
        }
        
        if(root->right){
            canRob += rob(root->right->left) + rob(root->right->right);
            dontRob += rob(root->right);
        }
        
        return dp[root] = max(canRob , dontRob);
    }
};