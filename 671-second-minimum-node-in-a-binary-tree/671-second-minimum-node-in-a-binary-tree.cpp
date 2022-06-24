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
    
    void storeInorder(TreeNode* root , set<int> &st){
        
        if(root == NULL){
            return;
        }
        
        storeInorder(root->left,st);
        st.insert(root->val);
        storeInorder(root->right,st);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        set<int> st;
        storeInorder(root,st);
        
      
        int cnt = 1;
        int ans;
        
        for(auto x : st){
            
            if(st.size() == 1){
                return -1;
                
            }
            if(cnt > 2){
                break;
            }
            cnt++;
            ans = x;
        }
        
        return ans;
    }
};