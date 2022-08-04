class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < n ; i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int curr = nums[i];
            int left = i+1;
            int right = n-1;
            
            int toFind = 0 - curr;
            
            while(left < right){
        
                if(nums[left] + nums[right] == toFind){
                    vector<int> v;
                    v.push_back(curr);
                    v.push_back(nums[left] );
                    v.push_back(nums[right]);
                    
                    ans.push_back(v);
                    
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    
                   left++;
                   right--;
                
                }
                
                else if(nums[left] + nums[right]  > toFind){
                    right--;
                }
                
                else{
                    left++;
                }
                
                
            }
           
        }
        
        return ans;
        
    }
};