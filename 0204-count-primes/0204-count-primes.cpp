class Solution {
public:
    //https://www.youtube.com/watch?v=5LMkddl2NCk
    /*
    SIEVE OF ERATHOSTHENES
    
    TC = O(log(LogN) * sqrt(N))
    SC = O(N)
    */
    
    int countPrimes(int n) {
        
        if(n <= 2){
            return 0;
        }
        
        vector<bool> composites(n , false);
        int limit = int(sqrt(n));
        int cnt = 0;
        
        for(int i = 2 ; i <= limit ; i++){
            if(composites[i] == false){
            for(int j = i*i ; j < n ; j+=i){
                composites[j] = true;
            }
        }
        }
        for(int i = 2 ; i < n ; i++){
            if(composites[i] == false){
                cnt++;
            }
        }
        
        return cnt;
        
    }
};