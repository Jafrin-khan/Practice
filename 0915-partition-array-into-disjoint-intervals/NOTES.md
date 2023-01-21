int n = nums.size();
int  ans = 1;
int max_1 = nums[0];
int curr = nums[0];
for(int i = 1; i < n; i++){
if(nums[i] < max_1){
max_1 = curr;
ans = i + 1;
}
else if(nums[i] > curr){
curr = nums[i];
}
}