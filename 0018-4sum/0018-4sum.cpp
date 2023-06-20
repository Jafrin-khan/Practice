class Solution {
    #define ll long long
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin() , nums.end());
        ll n = nums.size();
        
        for(ll i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            ll nT = target - nums[i];
            for(ll j = i + 1 ; j < n ; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                ll toFind = nT - nums[j];///////////////////////////////////////// DONT USE NT -= NUMS[J] AS NT VALUE HUM UPER WAALE LOOP SE LERE ISLIE CHANGE NI KR SKTE ISLIE HUME NAYA VARIABLE BANANE HAI 
                
                ll left = j + 1;
                ll right = n - 1;
                while(left < right){
                    if(nums[left] + nums[right] == toFind){
                        vector<int> v;
                        v = {nums[i] , nums[j] , nums[left] , nums[right]};
                        left++;
                        right--;
                        
                        ans.push_back(v);
                   
                    
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                    }
                    
                    else if((nums[left] + nums[right]) < toFind) left++;
                    else right--;
                }
            }
        }
        
        return ans;
    }
};