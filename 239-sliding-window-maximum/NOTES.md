class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
deque<int> dp;
int n = nums.size();
vector<int> ans;
for(int i = 0 ; i < n ; i++){
if(!dq.empty() && dq.front() == i - k ){
dq.pop_front();
}
while(!dq.empty() && nums[dq.back()] <= nums[i]){
dq.pop_back();
}
dp.push(i);
if(i >= k-1){
ans.push_back(nums[dq.front()]);
}
}
return ans;
}
};