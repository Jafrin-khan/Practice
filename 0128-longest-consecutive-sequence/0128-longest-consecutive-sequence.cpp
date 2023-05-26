class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
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
        
        for(int i = 0 ; i < nums.size() ; i++){//humne alag se har ele jo set mai hai usme traverse ni kiya kyunki TC badh jaati aur wo TLE dera tha pichle submission mai
            
            if(st.count(nums[i]-1) == 0){ // mtlb ye first ele hai seq ka
                curr = nums[i];
                currLen = 1;
            }
            
           
                while(st.count(curr + 1) != 0){ // mtlb subsequent ele dhundre hum...aage waale
                    curr+=1;
                    currLen++;
                }
                
                ans = max(ans , currLen);
            
            
        }
        
        return ans;
        
        
    }
};