class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        int n = nums.size();
       
        int min = 1e9;
        int ans = 0;
        
        for(int i = 0 ; i < n-2 ; i++){
            
            int left = i+1;
            int right = n-1;
          
            while(left < right){
               int sum = nums[i] + nums[left] + nums[right];
               int diff = abs(target - sum);
                
               if(diff < min){
                   min = diff;
                   ans = sum;
               }
                
              else if(sum < target){
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