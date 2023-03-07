class Solution {
public:
    /*
    Sliding window approach
    TC = O(N) + O(M)
    SC = O(26) + O(26)
    
    */
    
    bool checkFreq(vector<int>& freq1 , vector<int>& freq2){
         for(int i = 0; i < 26 ; i++){
             if(freq1[i] != freq2[i]) return false;
         }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return false;
        int n = s1.size();
        int m = s2.size();
        
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        for(int i = 0 ; i < n ; i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        
        int left = 0;
        int right = n-1;
        
        while(right < m){
            if(checkFreq(freq1,freq2)) return true;
            freq2[s2[left]-'a']--;
            left++;
            right++;
            if(right <= m-1){
            freq2[s2[right]-'a']++;
            }
        }
        
        return false;
        
    }
};