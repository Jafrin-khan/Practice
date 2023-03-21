class Solution {
public:
    
    /*
    //Approach 1
    int singleNonDuplicate(vector<int>& nums) {
        
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            ans = nums[i]^ans;
                
        }
        
        return ans;
    }*/
    
     //https://www.youtube.com/watch?v=PzszoiY5XMQ
    
    /*
    TC = O(logN)
    SC = O(1)
    */
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-2;//imp
        
        while(low <= high){
            int mid = (low + high)>>1;
            if(nums[mid] == nums[mid^1]) low = mid+1;//xor gives prev even iff mid is odd Or gives next odd if even
            else high = mid-1;
        }
        
        return nums[low];
    }
};