class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
         if(nums.size() == 0){
            return 0;
        }
        
        unordered_set<int> st;
        
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]);
        }
        
        int ans = 0;
        int curr;
        int currLen;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(st.count(nums[i]-1) == 0){
                curr = nums[i];
                currLen = 1;
            }
            
           
                while(st.count(curr + 1) != 0){
                    curr+=1;
                    currLen++;
                }
                
                ans = max(ans , currLen);
            
            
        }
        
        return ans;
        
        
    }
};