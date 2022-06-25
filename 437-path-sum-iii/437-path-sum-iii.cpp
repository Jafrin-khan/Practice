class Solution {
public:
    int count=0;
    void recursive(TreeNode* root, long long sum, int targetSum){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        
        if(sum==targetSum){
            count++;
        }
        //cout<<"sum=> "<<sum<<" count=> "<<count<<endl;
            recursive(root->left, sum,targetSum);
            recursive(root->right, sum, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        long long sum=0;
        recursive(root, sum, targetSum);
        //cout<<"cout=> "<<count<<endl;
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
};