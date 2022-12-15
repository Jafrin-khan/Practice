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
        
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root , 0});
        
        long long left = 0;
        long long right = 0;
        
        long long maxWidth = 0;
        
        while(!q.empty()){
            
            long long k = q.size();
            long long line = q.front().second;
            
            for(long long i = 0 ; i < k ; i++){
                
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                long long currLine = front.second - line;
                
                if(i == 0){
                    left = currLine;
                }
                
                if(i == k-1){
                    right = currLine;
                }
                
                if(node->left){
                    q.push({node->left , 2*currLine+1});
                }
                
                if(node->right){
                    q.push({node->right , 2*currLine+2});
                }
                
                maxWidth = max(maxWidth , right-left+1);
            }
        }
        
        return maxWidth;
        
    }
};