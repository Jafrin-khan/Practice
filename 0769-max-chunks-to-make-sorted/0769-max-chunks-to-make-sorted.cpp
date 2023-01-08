class Solution {
public:
    
    /*
    Just an algorithm that you should know
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