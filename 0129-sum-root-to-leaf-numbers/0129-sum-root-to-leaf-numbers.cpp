
class Solution {
public:
    
    /*
    TC = O(N)
    SC = O(N)....stack space
    */
    void f(TreeNode* root , int& sum , int k){
        
        if(root == NULL){
            return;
        }
         k = 10*k + (root->val);
        if(root->left == NULL && root->right == NULL){
            sum = sum + k;
            return;
        }
        
        f(root->left , sum , k);
        f(root->right , sum , k);
        
    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        int k = 0;
        f(root , sum , k);
        
        return sum;
    }
};