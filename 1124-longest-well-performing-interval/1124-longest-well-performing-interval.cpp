class Solution {
public:
    
    //simple sliding window
    int longestWPI(vector<int>& hours) {
        
        int ans = 0;
        int cnt = 0;
        int n = hours.size();
        
        for(int i = 0 ; i < n ; i++){
            if(hours[i] > 8)cnt++;
            if(cnt*2 > i+1)ans = i+1;
            int currCnt = cnt;
            int left = 0;
            while(left < i && 2*currCnt <= i - left + 1){
                if(hours[left] > 8) currCnt--;
                 left++;
                if(2*currCnt > i - left + 1) ans = max(ans , i-left+1);
            }
        }
        
        return ans;
       
    }
};