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
    TC = O(N) + O(NlogN)
    SC = O(N)
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            vector<int> v;
            int size = q.size();
            
            while(size--){
                
                TreeNode* front = q.front();
                q.pop();
                
                v.push_back(front->val);
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
            
            ans.push_back(v);
            
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};