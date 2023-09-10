class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        long long n = nums.size();
        sort(nums.begin() , nums.end());
        
        vector<vector<int>> ans;
        
        for(long long i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            long long nT = target - nums[i];
            for(long long j = i+1 ; j < n ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                long long k = nT - nums[j];
                
                long long left = j+1;
                long long right = n-1;
                while(left < right){
                    if(nums[left] + nums[right] == k){
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;right--;
                        
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    
                    else if(nums[left] + nums[right] < k){
                        left++;
                    }
                    
                    else right--;
                }
            }
        }
        
        return ans;
    }
};