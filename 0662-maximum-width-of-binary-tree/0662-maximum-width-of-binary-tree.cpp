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
    int widthOfBinaryTree(TreeNode* root) {
                                            
        if(root == NULL) return 0;
                                                 
        queue<pair<TreeNode* , long long int>> q;
        q.push({root , 0});
        
        long long int width = 0;
        
        while(!q.empty()){
            
            long long int size = q.size();
            long long int line = q.front().second;
            
            long long int left = 0 , right = 0;
            
            for(long long int i = 0 ; i < size ; i++){
                long long int curr = q.front().second - line;
                TreeNode* node = q.front().first; q.pop();
                
                if(i == 0) left = curr;
                if(i == size-1) right = curr;
                width = max(width , right - left + 1);
                
                if(node->left) q.push({node->left , 2*curr+1});
                if(node->right) q.push({node->right , 2*curr+2});
            }
               
        }
        return width;
    }
};