class Solution {
public:
    
    /*
    Just an algorithm that you should know...remember we can use this algo as it is written " permutation of the integers in the range [0, n - 1]"
    
    see this problem for real algo :  Max Chunks To Make Sorted II
    
    TC = O(N)
    SC = O(1)
    */
    
    int maxChunksToSorted(vector<int>& arr) {
        
        int idx = 0;
        int currSum = 0;
        int ans = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            idx += i;
            currSum += arr[i];
            
            if(idx == currSum){
                ans++;
            }
        }
        
        return ans;
    }
};