class Solution {
public:
    
    //Moore's voting algorithm
    
    /*
    TC = O(N)
    SC = O(1)
    */
    
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
        int currMajority = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(cnt){
                cnt += (nums[i] == currMajority ? 1 : -1);
            }
            
            else{
                currMajority = nums[i];
                cnt = 1;
            }
        }
        
        return currMajority;
    }
};