set<vector<int>> st;
void f(int ind , vector<int>& nums, int target , vector<int> helper){
if(target == 0){
sort(helper.begin() , helper.end());
st.insert(helper);
}
for(int i = ind ; i < nums.size() ; i++){
if(i > ind && nums[i] == nums[i-1]){
continue;
}
if(nums[i] > target){
break;
}
helper.push_back(nums[i]);
f(i + 1 , nums , target-nums[i] , helper);
helper.pop_back();
}
}
vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
vector<vector<int>> ans;
sort(nums.begin(),nums.end());
vector<int> helper;
f(0 , nums , target , helper);
for(auto x : st){
ans.push_back(x);
}
return ans;
}