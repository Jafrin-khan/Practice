
class Solution {
public:
    
    int f(TreeNode* root , int& maxSum){
        
        if(root == NULL) return 0;
        
        int ls = max(0 , f(root->left , maxSum));
        int rs = max(0 , f(root->right , maxSum));
        
        maxSum = max(maxSum , ls + rs + root->val);
        
        return max(ls , rs) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum = -1e9;
        f(root , maxSum);
        
        return maxSum;
    }
};