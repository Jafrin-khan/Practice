class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < n ; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            long long k = target - nums[i];
            for(int j = i+1 ; j < n ; j++){
               if(j != i+1 && nums[j] == nums[j-1]) continue;
                long long kk = k - nums[j];
                
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    if(nums[left] + nums[right] == kk) {
                    ans.push_back({nums[i] , nums[j] , nums[left++] , nums[right--]});
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    
                    else if(nums[left] + nums[right] < kk) left++;
                    else right--;
                }
            }
        }
        
        return ans;
    }
};