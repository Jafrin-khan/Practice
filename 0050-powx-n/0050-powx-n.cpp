class Solution {
public:
    
    double myPow(double x, int n) {
        
        long nn = abs(n);
        double ans = 1.0;
        
        while(nn){
            
            if(nn%2){
                ans *= x;
                nn--;
            }
            
            else {
                x = x*x;
                nn/=2;
            }
        }
        
        if(n < 0) return (double)(1.0)/(double)(ans);
        
        return ans;
        
    }
};