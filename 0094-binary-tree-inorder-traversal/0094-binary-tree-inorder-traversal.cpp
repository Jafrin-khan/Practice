
class Solution {
public:
    /*
    //Recursion
    //TC = O(N)
    //SC = O(N)
    void inOrder(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;
        
        
        inOrder(root->left , ans);
        ans.push_back(root->val);
        inOrder(root->right , ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root , ans);
        
        return ans;
    }
    */
    
    
    /*
    //Iterative
    //TC = O(N)
    //SC = O(N)
   
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        
        while(true){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) break;
                root = st.top();st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        
        return ans;
    }
    */
    
    //MORRIS
    //O(N)
    //O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr != NULL){
            
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == curr){
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                
                else{
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }
        
        return ans;
    }
    
    
};