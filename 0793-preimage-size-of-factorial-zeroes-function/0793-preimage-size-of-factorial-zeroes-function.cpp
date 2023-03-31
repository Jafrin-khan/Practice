class Solution {
public:
    
      long long f(long long num){
            long long cnt = 0;
            while(num){
                cnt += (num/5);
                num/=5;
            }
            return cnt;
        }
        int findNum(long long n)
        {
            if(n == 0) n = 1;
            long long ans = 0;
            
            long long low = 1;
            long long high = n*5;
            
            while(low <= high){
                long long mid = low + (high-low)/2;
                long long check = f(mid);
                
                if(check >= n){
                    if(check == n ) return 5;
                    high = mid-1;
                   
                }
                
                else  low = mid+1;
            }
        
           return 0;
        }
    int preimageSizeFZF(int k) {
        return findNum(k);
    }
};