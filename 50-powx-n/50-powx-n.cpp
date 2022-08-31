class Solution {
public:
    double myPow(double x, int n) {
        
        bool sign = false;
        if(n < 0){
            sign = true;
        }
        
        long nn = abs(n);
        double ans = 1.0;
        
        while(nn > 0){
            
            if(nn%2 != 0){
                ans *= x;
                nn = nn-1;
            }
            
            else{
                x=(x*x);
                nn = nn/2;
            }
        }
        
        if(sign){
            return (1.0/ans);
        }
        return ans;
        
    }
};