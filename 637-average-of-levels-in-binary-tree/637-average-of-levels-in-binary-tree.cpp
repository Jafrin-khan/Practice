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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> v;
            for(int i = 0 ; i < size ; i++){
            
            TreeNode* node = q.front();
            v.push_back(node->val);
            q.pop();
            
            if(node->left){
                q.push(node->left);
            }
            
            if(node->right){
                q.push(node->right);
            }
        }
            
        double avg = 0;
        for(auto x : v){
            avg += x;
        }
        avg/=v.size();
        ans.push_back(avg);
        }
        
        return ans;
    }
};