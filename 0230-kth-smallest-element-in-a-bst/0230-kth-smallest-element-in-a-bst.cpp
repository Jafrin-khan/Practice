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
    TC = O(n)
    SC = O(h)
    
    there is also a method of SC = O(1) using Morris Traversal gfg documentation ,, refer that
    */
    
    void f(TreeNode* root , int k , int& ans , int&cnt){
        
        if(root == NULL || cnt > k){
            return;
        }
        f(root->left , k , ans , cnt);
        cnt++;
        if(cnt == k){
            ans = root->val;
        }
        f(root->right , k , ans , cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans;
        int cnt = 0;
        f(root , k , ans , cnt);
        
        return ans;
    }
};