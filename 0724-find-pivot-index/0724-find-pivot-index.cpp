class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       
       int n = nums.size();
       int sum = 0;
       
       for(int i = 0 ; i < n ; i++) sum += nums[i];
       for(int i = 0 ; i < n ; i++){
           if((sum-nums[i])%2 == 0){
               int l = 0;
               int r = n-1;
               int sumL = 0;
               int sumR = 0;
               while(l < i){
                   sumL += nums[l++];
               }
               while(r > i){
                   sumR += nums[r--];
               }
               
               if(sumL == sumR) return i;
           }
       }
       
       return -1;
    }
};