
class Solution {
public:
    
    int f(TreeNode* root , int& maxSum){
        if(root == NULL) return 0;
        
        int sumL = max({0 , f(root->left , maxSum)});
        int sumR = max({0 , f(root->right , maxSum)});
        
        maxSum = max(maxSum , sumL + sumR + root->val);
        
        return max(sumL , sumR) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        int maxSum = -1e9;
        f(root , maxSum);
        
        return maxSum;
    }
};