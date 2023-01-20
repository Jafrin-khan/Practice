    
#include<bits/stdc++.h>
class Solution {
public:
    
    /* check tc
    TC = O(NlogN) + O(N^2) ~ O(N^2)
    SC = O(N^2) + O(3)
    */



    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;
        
        if(n < 3){
            return ans;
        }
        
        for(int i = 0 ; i < n-2 ; i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int left = i+1;
            int right = n-1;
            int toFind = 0 - nums[i];
            
            while(left < right){
               
                if(nums[left] + nums[right] == toFind){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
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
                
                else if(nums[left] + nums[right] < toFind){
                    left++;
                }
                
                else{
                    right--;
                }
            }
          
        }
        
        return ans;
        
    }
};