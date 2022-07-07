class Solution {
public:
    
      int help(vector<int>&a,int n,int com,unordered_map<int,int>dp[]){
        if(n<0){
            return com;
        }
     
         if(dp[n].find(com)!=dp[n].end())return dp[n][com];
        
        int n1=help(a,n-1,com*a[n],dp);
        int n2=help(a,n-1,a[n],dp);
        
        int val= max(n1,max(com,n2));
        dp[n][com]=val;
        return val;
       
    }
    
public:
    int maxProduct(vector<int>& nums) {
        
        int computed=nums[nums.size()-1]; 
       
        unordered_map<int,int>dp[nums.size()];
        int res=help(nums,nums.size()-2,nums[nums.size()-1],dp);
         return res;
    }
   
};