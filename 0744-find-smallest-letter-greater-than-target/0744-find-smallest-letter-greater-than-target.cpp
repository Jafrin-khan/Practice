class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int tar = target - 'a';
        
        int low = 0;
        int high = letters.size()-1;
        
        int ans = 1e9;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if((letters[mid] - 'a') > tar) {ans = min(ans , letters[mid]-'a');high = mid-1;}
            else low = mid+1;
        }
        if(ans == 1e9) return letters[0];
        
        return ans+'a';
    }
};