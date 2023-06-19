class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left < right){
                if(nums[left] + nums[right] == target){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    
                    ans.push_back(v);
                    
                    left++;
                    right--;
                    
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                
                else if(nums[left] + nums[right] < target){
                    left++;
                }
                
                else right--;
            }
        }
        
        return ans;
    }
};