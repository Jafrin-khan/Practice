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
        queue<pair<TreeNode*,long long int>> q;
        q.push({root , 0});
        
        long long int first;
        long long int last;
        
        long long int ans = 0;
        while(!q.empty()){
            
            long long int size = q.size();
            long long int toSubtract = q.front().second;
            
            for(int i = 0 ; i < size ; i++){
                
                long long int currInd = q.front().second - toSubtract;
                TreeNode* front = q.front().first;
                q.pop();
                
                if(i == 0){
                    first = currInd;
                }
                
                if(i == size-1){
                    last = currInd;
                }
                
                if(front->left){
                    q.push({front->left , 2*currInd + 1});
                }
                
                if(front->right){
                    q.push({front->right , 2*currInd + 2});
                }
                
                ans = max(ans , last - first +1);
            }
        }
        
        return ans;
    }
};