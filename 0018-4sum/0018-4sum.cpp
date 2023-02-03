class Solution {
    #define ll long long
public:
   /*
   TC = O(n*(n*(logn)))
   SC = 
   */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        
        for(ll i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            ll nt = target - nums[i];
            for(int j = i+1 ; j < n ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                ll left = j+1;
                ll right = n-1;
                ll toFind = nt-nums[j];
                while(left < right){
                    if(nums[left] + nums[right] == toFind){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]){left++;}
                        while(left < right && nums[right] == nums[right+1]){right--;}
                    }
                    
                    else if(nums[left] + nums[right] < toFind){
                        left++;
                    }
                    
                    else{
                        right--;
                    }
                     
                }
               
              
            }
        }
        
        return ans;
    }
};