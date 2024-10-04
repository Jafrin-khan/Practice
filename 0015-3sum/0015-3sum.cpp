class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int num = -1*nums[i];
            
            int left = i+1;
            int right = n-1;
            
            while(left < right){
                if(nums[left] + nums[right] == num){
                    ans.push_back({nums[i] , nums[left++] , nums[right--]});
                    
                while(left < right && nums[left] == nums[left-1]) left++;
                while(right < n && left < right && nums[right] == nums[right+1]) right--;
                }
                
                else if(nums[left] + nums[right] < num) left++;
                else right--;
                
               
                
            }
        }
        
        return ans;
    }
};