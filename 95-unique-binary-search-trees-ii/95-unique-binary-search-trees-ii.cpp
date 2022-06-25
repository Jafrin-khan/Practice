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
    
    vector<TreeNode*> solve(int s , int e){
        
        vector<TreeNode*> ans;
        
        if(s > e){
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i = s ; i <= e ; i++){
            
            vector<TreeNode*> left = solve(s , i-1);
            vector<TreeNode*> right = solve(i+1 , e);
            
            for(auto x : left){
                for(auto y : right){
                    TreeNode* node = new TreeNode(i);
                    node->left = x;
                    node->right = y;
                    
                    ans.push_back(node);
                }
            }
            
            
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};