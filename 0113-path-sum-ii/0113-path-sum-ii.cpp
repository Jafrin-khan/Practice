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
    
    void f(TreeNode* root , int k , vector<int>helper , vector<vector<int>>& ans){
        
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL && root->val == k){
            helper.push_back(root->val);
            ans.push_back(helper);
            return;
        }
        
        helper.push_back(root->val);
        f(root->left , k - root->val , helper , ans);
        f(root->right , k - root->val , helper , ans);
        helper.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> helper;
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        f(root , targetSum , helper , ans);
        return ans;
        
    }
};