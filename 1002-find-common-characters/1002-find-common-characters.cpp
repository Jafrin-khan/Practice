class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<string> ans;
        
        vector<int> original(26,0);
        
        for(auto it : words[0]) original[it-'a']++;
        
        for(auto word : words){
            vector<int> copy(26,0);
            for(auto it : word) copy[it - 'a']++;
            
            for(int i = 0 ; i < 26 ; i++){
            original[i] = min(original[i] , copy[i]);
            }
        }
        
        for(int i = 0 ; i < 26 ; i++){
            int cnt = original[i];
            while(cnt--){
                string s = "";
                s += (i+'a');
                ans.push_back(s);
            }    
        }
        
        return ans;
    }
};