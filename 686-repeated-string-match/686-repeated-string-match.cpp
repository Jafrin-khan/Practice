class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int cnt = 1;
        string orig = a;
        for(int i = 0 ; i < (b.size()/orig.size()) + 2 ; i++){
            if(a.find(b) == -1){
                a += orig;
                cnt++;
            }
            
            else{
                return cnt;
            }
        }
        
        return -1;
        
    }
};