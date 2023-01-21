class Solution {
public:
    
    //https://www.youtube.com/watch?v=jZcAldZP1ag
    
  //  TC = O(N^2)
  
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        int ans= 0;
        
        for(int i = 0 ; i < n ; i++){
            vector<int> cnt(101 , 0);
            for(int j = i+1 ; j < n ; j++){
                int k = target - arr[j] - arr[i];
                if(k>=0 && k <= 100 && cnt[k]>0){
                    ans += cnt[k];
                    ans = ans%1000000007;
                }
                cnt[arr[j]]++;
            }
        }
        
        return ans;
    }
};