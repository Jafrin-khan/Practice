class Solution {
public:
int widthOfBinaryTree(TreeNode* root) {
if(root==NULL)
return 0;
long long int ans = 0;
queue<pair<TreeNode*,long long int>> q;
q.push({root,0});
while(!q.empty()){
long long int size = q.size();
long long int mmin = q.front().second;    //making index starting from zero so that we can avoid overflow
long long int first,last;
for(int i=0; i<size; i++){
long long int cur_id = q.front().second-mmin;
TreeNode* node = q.front().first;
q.pop();
if(i==0) first = cur_id;
if(i==size-1) last = cur_id;
if(node->left)
q.push({node->left, cur_id*2});
if(node->right)
q.push({node->right, cur_id*2+1});
}
ans = max(ans, last-first+1);
}
return ans;
}
};