/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; || (root->left == NULL && root->right == NULL)
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        
        
        if(root == NULL){
            return ans;
        }
        
       
        
        stack<TreeNode*> lr;
        stack<TreeNode*> rl;
        
        lr.push(root);
        while(!lr.empty() || !rl.empty()){
               
            vector<int> v;
            if(!lr.empty()){
                
                while(!lr.empty()){
                TreeNode* front = lr.top();
                lr.pop();
                
                v.push_back(front->val);
                
                if(front->left){
                    rl.push(front->left);
                }
                
                if(front->right){
                    rl.push(front->right);
                }  
            }}
            
            else{
                
                while(!rl.empty()){
                 TreeNode* front = rl.top();
                rl.pop();
                
                v.push_back(front->val);
                
                if(front->right){
                    lr.push(front->right);
                }
                
                if(front->left){
                    lr.push(front->left);
                }  
                
            }
            }  
            ans.push_back(v);
        }
        
        return ans;
         
    }
};