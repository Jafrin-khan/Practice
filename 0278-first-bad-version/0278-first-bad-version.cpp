// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1;
        int high = n;
        
        int ans;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            bool isBad = isBadVersion(mid);
            
            if(isBad){
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        
        return ans;
    }
    
    /*
    TC = O(logN)
    SC = O(1)
    */
};