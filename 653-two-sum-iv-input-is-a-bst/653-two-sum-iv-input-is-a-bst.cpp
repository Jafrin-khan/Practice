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
    
    int ans = false;
    unordered_map<int,int> mp;
    bool f(TreeNode* root , int k){
        
        if(root == NULL){
            return false;
        }
        
        if(ans == true){
            return true;
        }
        
        f(root->left , k);
        
        if(mp.find(k-root->val) != mp.end()){
            ans = true;
        }
        
        mp[root->val]++;
        f(root->right , k);
        
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        
        return f(root , k);
    }
};