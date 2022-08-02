void f(vector<int>&nums , vector<int> helper ,set<vector<int>>& ans , vector<int> freq){
if(helper.size() == nums.size()){
ans.insert(helper);
return;
}
for(int i = 0 ; i < nums.size() ; i++){
if(freq[i] != 1){
helper.push_back(nums[i]);
freq[i] = 1;
f(nums , helper , ans , freq);
freq[i] = 0;
helper.pop_back();
}
}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
set<vector<int>> ans;
vector<int> freq(nums.size() , 0);
vector<int> helper;
f(nums , helper , ans , freq);
vector<vector<int>> toReturn;
for(auto x : ans){
toReturn.push_back(x);
}
return toReturn;
}