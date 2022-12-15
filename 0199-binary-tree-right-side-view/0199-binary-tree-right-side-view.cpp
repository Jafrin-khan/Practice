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
    TC = O(N)
    SC = O(N)
    */
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL){
            return {};
        }
        
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        
        while(!q.empty()){
            
            int k = q.size();
            
            for(int i = 0 ; i < k ; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                if(i == k-1){
                    ans.push_back(front->val);
                }
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }  
            }
        }
        
        return ans;
        
    }
};