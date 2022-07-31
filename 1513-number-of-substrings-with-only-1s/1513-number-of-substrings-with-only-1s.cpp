class Solution {
public:
    int numSub(string s) {
        
        int i=0,j=0;
        int n = s.size();
        int res=0;
        for(;j<=n;j++){
            if(s[j]=='0' or j==n){ // the moment our window breaks we will do our caclulation.
                long long len =j-i;
                if(len>0){
                    long long sum = ((len*(len+1))%1000000007)/2; // as the contribution of the length is (n+1)*n/2;
                    res += sum%1000000007;
                }
                i=j+1;// set lower bound of window to the next of break point.
            }
        }
        return res;
        
    }
};