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
    
    int count = 0;
    void f(TreeNode* root,long long sum , int targetSum){
        
        if(root == NULL){
            return;
        }
        
        sum += root->val;
        
        if(sum == targetSum){
            count++;
        }
        
        f(root->left , sum , targetSum);
        f(root->right , sum , targetSum);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL){
            return 0;
        }
        
        int sum = 0;
        f(root , sum , targetSum);
        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);
        
        return count;
    }
};