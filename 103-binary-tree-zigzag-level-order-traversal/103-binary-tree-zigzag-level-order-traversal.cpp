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
                    TreeNode* front = LR.top();
                    LR.pop();
                    v.push_back(front->val);
                    
                    if(front->left){
                        RL.push(front->left);
                    }
                    
                    if(front->right){
                        RL.push(front->right);
                    }
                }
            }
            
            else{
                
                while(!RL.empty()){
                    TreeNode* front = RL.top();
                    RL.pop();
                    v.push_back(front->val);
                    
                    if(front->right){
                        LR.push(front->right);
                    }
                    
                    if(front->left){
                        LR.push(front->left);
                    }
                }
                
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};