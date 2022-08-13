class Solution {
public:
    
    int gcd(int a , int b){
        
        if(a == 0){
            return b;
        }
        
        if(b == 0){
            return a;
        }
        
        return gcd(b , a%b);
    }
    string gcdOfStrings(string s1, string s2) {
        
     int n = s1.size();
     int m = s2.size();
        
     int GCD = gcd(n , m);
        
     return s1 + s2 == s2 + s1 ? s1.substr(0 , GCD) : "";
        
    }
};