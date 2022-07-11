class Solution {
public:
void f(set<vector<int>> & ans , vector<int> helper , vector<int> freq , vector<int>& nums){
if(helper.size() == nums.size()){
ans.insert(helper);
return;
}
for(int i = 0 ; i < nums.size() ; i++){
if(freq[i] != 1){
helper.push_back(nums[i]);
freq[i] = 1;
f(ans,helper,freq,nums);
freq[i] = 0;
helper.pop_back();
}
}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
set<vector<int>> ans;
vector<int> helper;
vector<int> freq(nums.size(),0);
vector<vector<int>> FAns;
f(ans,helper,freq , nums);
for(auto x : ans){
FAns.push_back(x);
}
return FAns;
}
};