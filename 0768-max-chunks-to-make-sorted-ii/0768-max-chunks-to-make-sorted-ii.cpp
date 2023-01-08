class Solution {
public:
    
    /*
    Just an algorithm that u should know
    TC = O(NlogN) + O(N)
    SC = O(N)
    */
    
    int maxChunksToSorted(vector<int>& arr) {
        
        vector<int> copy = arr;
        sort(copy.begin() , copy.end());
        
        long long sum1 = 0 , sum2 = 0;
        int ans = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            sum1 += copy[i];
            sum2 += arr[i];
            
            if(sum1 == sum2){
                ans++;
            }
        }
        
        return ans;
       
    }
};