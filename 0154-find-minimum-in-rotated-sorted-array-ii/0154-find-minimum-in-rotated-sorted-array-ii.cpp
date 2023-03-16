class Solution {
public:
/*
The only case which makes it different from the question with distinct elements is when the first and last element will be equal. In such case, just decrease the search space till we find nums[0]!=nums[n-1] and then do simple binary search.

};
*/
    
/*
TC = O(logN)
SC = O(1)
*/
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;
        int high = n-1;
        int ans = 1e9;
        
        while(low <= high){
            int mid = low+(high-low)/2;
            
            if((nums[low] == nums[mid]) && nums[mid] == nums[high]){
                ans = min(ans , nums[mid]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<= nums[mid]){
                ans= min(ans,nums[low]);
                low=mid+1;
            }else{
                ans =min(ans,nums[mid]);
                high=mid-1;
            }
        
        }
        
        return ans;
    }
};