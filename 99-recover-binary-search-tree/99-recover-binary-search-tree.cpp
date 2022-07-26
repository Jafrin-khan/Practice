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
    int i = 0;
    void store(TreeNode* root , vector<int>& v){
        
        if(root == NULL){
            return;
        }
        
        store(root->left , v);
        v.push_back(root->val);
        store(root->right , v);
    }
    
    void change(TreeNode* root , vector<int>& v){
         if(root == NULL){
            return;
        }
        
        change(root->left , v);
        if(v[i] != root->val){
            root->val = v[i];
        }
        i++;
        change(root->right , v);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        vector<int> v;
        store(root , v);
        
        sort(v.begin() , v.end());
        
        change(root , v);

    }
};