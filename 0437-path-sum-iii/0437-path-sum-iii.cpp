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
    TC = O(NlogN)
    SC = O(N)
    */
    void f(TreeNode* root , long long k , int& cnt){
        
        if(root == NULL) return;
        if(root->val == k){
            cnt++;
            //dont return here consider this eg test case 
           /* [1,-2,-3,1,3,-2,null,-1]
              -1
              here the ans should be 4 but it gives 3 hence we dont need to return from here
            */
        } 
        
        f(root->left , k - root->val , cnt);
        f(root->right , k- root->val , cnt);
    }
   
    void helper(TreeNode* root, long long k , int& cnt){
         
        if(root == NULL) return;
        
        f(root , k , cnt);
        helper(root->left,k , cnt);
        helper(root->right,k , cnt);
        
    }
    int pathSum(TreeNode* root, int target) {
       int cnt = 0;
       long long k = target;
       helper(root,k,cnt);
        
       return cnt;
        
    }
};