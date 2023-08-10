bool f(TreeNode* root , int k , unordered_map<int,int>& mp){
if(root == NULL) return false;
int toFind = k - root->val;
if(mp.find(toFind) != mp.end()) return true;
mp[root->val]++;
return f(root->left , k , mp) || f(root->right , k , mp);
}
bool findTarget(TreeNode* root, int k) {
5
unordered_map<int,int> mp;
return f(root , k , mp);
}