class Solution {
public:
    
    //BNY Mellon
    
    /*
    TC = O(N)
    SC = O(N)
    */
    
    //Sliding Window
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        int res = 0, left = -1, right = -1;
        
        for (int i = 0; i < n; i++) {
            if (A[i] >= L && A[i] <= R)
                right = i;
            else if (A[i] > R) {
                left = right = i;
            }
            res += right-left;
        }
    
        return res;
    }
};