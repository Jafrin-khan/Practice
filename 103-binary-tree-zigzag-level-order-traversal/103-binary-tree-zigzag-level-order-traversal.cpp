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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> LR;
        stack<TreeNode*> RL;
        
        
        
        LR.push(root);
        
        while(!LR.empty() || !RL.empty()){
            
            vector<int> v;
            if(RL.empty()){
                
                while(!LR.empty()){
                TreeNode* node = LR.top();
                LR.pop();
                v.push_back(node->val);
                  
                if(node->left){
                    RL.push(node->left);
                }
                if(node->right){
                    RL.push(node->right);
                }
              
                }
            }
            
            else{
                
                while(!RL.empty()){
                TreeNode* node = RL.top();
                RL.pop();
                v.push_back(node->val);
               
                if(node->right){
                    LR.push(node->right);
                }
                    
                     
                 if(node->left){
                    LR.push(node->left);
                }
            }}
            
            ans.push_back(v);
        }
        
        return ans;
        
    }
};