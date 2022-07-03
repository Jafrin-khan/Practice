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
    int temp = INT_MAX;
    void store(TreeNode* root , int& ans){
        
        if(root == NULL){
            return;
        }
        
        store(root->left , ans);
        ans = min(ans , abs(root->val-temp));
        temp = root->val;
        store(root->right , ans);
    }
    int minDiffInBST(TreeNode* root) {
        
        vector<int> v;
        int ans = INT_MAX;
        
        store(root , ans);
        return ans;
      
    }
};