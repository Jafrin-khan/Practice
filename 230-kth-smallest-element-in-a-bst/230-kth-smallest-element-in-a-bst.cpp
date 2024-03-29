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
    
    int ans;
    void inOrder(TreeNode* root, int k , int &cnt){
        
        if(root == NULL){
            return;
        }
        
        if(cnt > k){
            return;
        }
       
        inOrder(root->left , k , cnt);
        cnt++;
         
        if(k == cnt){
            ans = root->val;
    
        }
        inOrder(root->right , k, cnt);
  
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;
        inOrder(root , k , cnt);
        
        return ans;
        
    }
};