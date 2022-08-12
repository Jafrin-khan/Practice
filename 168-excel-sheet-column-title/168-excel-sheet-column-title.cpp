class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        int rem = 0, quo = columnNumber;
        string res = "";
        
        while(quo > 0){
            rem = (quo % 26) ? (quo % 26) : 26 ;
            quo = (quo - rem) / 26;
            res = char('A'+rem - 1) + res;
        }
        
        return res;
        
    
    
    // quotient = cn / 26
    // rem = cn % 26
        
        
    }
};