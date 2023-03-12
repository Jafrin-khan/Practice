class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int left = 0 , right = n-1;
        
        bool found1 = false;
        int first = -1;
        
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                found1 = true;
                first = mid;break;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        
        if(!found1) {
            return {-1,-1};
        }
        
        int second = -1;
        int l = first;
        int r = first;
        
        while(l >= 0 && nums[l] == target){
            first = min(first,l);
            l--;
        }
        
        while(r < n && nums[r] == target){
            second = max(second,r);
            r++;
        }
        
        return {first,second};
        
    }
};