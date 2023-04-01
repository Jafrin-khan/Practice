/*
Approach for this Problem:
If x is 0, return 0.
Initialize first to 1 and last to x.
While first is less than or equal to last, do the following:
a. Compute mid as first + (last - first) / 2.
b. If mid * mid equals x, return mid.
c. If mid * mid is greater than x, update last to mid - 1.
d. If mid * mid is less than x, update first to mid + 1.
Return last.
*/

class Solution {
public:
    /*
    TC = O(logN)
    SC = O(1)
    */
    int mySqrt(int x) {
        
        long long low = 1 , high = x;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid > x) high = mid-1;
            else low = mid+1;
        }
        
        return high;
    }
};