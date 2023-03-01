class Solution {
public:
    /*
    https://www.youtube.com/watch?v=dw79Uf4s3cA
    TC = O(N)
    SC = O(1)
    */
    int minFlipsMonoIncr(string s) {
        
        int cnt1 = 0;
        int ans = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1') cnt1++;
            else{
                ans = min(ans+1 , cnt1);
            }
        }
        return ans;
    }
};