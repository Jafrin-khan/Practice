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
    https://www.youtube.com/watch?v=rAztd-UzAjU
    */
    int f(TreeNode* root , int& ans){
        
        if(root == NULL){
            return 0;
        }
        
        int leftSteps = f(root->left,ans);
        int rightSteps = f(root->right,ans);
        ans += abs(leftSteps) + abs(rightSteps);
        
        return root->val + leftSteps + rightSteps - 1; 
    }
    
    int distributeCoins(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int ans = 0;
        f(root,ans);
        
        return ans;
        
    }
};