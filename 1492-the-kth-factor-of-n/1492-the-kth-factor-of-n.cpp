class Solution {
public:
    int kthFactor(int n, int k) {
        
        int cnt = 1;
        int ans = -1 ;
        
        for(int i = 1 ; i <= n ; i++){
            
            if(n%i == 0){
                if(cnt == k){
                    ans = i;
                    break;
                }
                
                else{
                    cnt++;
                }
            }
        }
        
        return ans;
        
    }
};