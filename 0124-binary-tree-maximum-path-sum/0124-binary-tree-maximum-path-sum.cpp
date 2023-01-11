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
    int f(TreeNode* root , int& maxSum){
        
        if(root == NULL){
            return 0;
        }
        
        int sumLeft = max(0 , f(root->left , maxSum));
        int sumRight = max(0 , f(root->right , maxSum));
        
        maxSum = max(maxSum , sumLeft + sumRight + root->val);
        
        return max(sumLeft , sumRight) + root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int maxSum = -1e9;
        f(root , maxSum);
        
        return maxSum;
    }
};