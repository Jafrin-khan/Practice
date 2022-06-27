class Solution {
public:
    int minPartitions(string s) {
        
        int maxi = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            int num = s[i] - '0';
            maxi = max(maxi , num);
        }
        
        return maxi;
    }
};

