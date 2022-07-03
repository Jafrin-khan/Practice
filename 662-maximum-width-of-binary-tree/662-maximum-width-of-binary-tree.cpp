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
        
        queue<pair<TreeNode* ,long long int>> q;
        q.push({root , 0});
        
        long long int left;
        long long int right;
            
        
        long long int width = 0;
        
        while(!q.empty()){
            
            long long int size = q.size();
            long long int startIndex = q.front().second;
         
            for(int i = 0 ; i < size ; i++){
                
                auto front = q.front();
                q.pop();
                
                TreeNode* node = front.first;
                long long int line = front.second - startIndex;
                
                if(i == 0){
                    left = line;
                }
                
                if(i == size-1){
                    right = line;
                }
                
                width = max(width , right-left+1);
                
                if(node->left){
                    q.push({node->left , 2*line+1});
                }
                
                if(node->right){
                    q.push({node->right , 2*line+2});
                }
            }
            
        }
        
        return width;
        
    }
};